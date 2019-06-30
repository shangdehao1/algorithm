#ifndef COND_H
#define COND_H

#include <thread>
#include "mutex.h"
#include "../context/context.h"

/*

  pthread_cond_wait have the following steps : 
    - 在调用pthread_cond_wait之前，参数mutex必须被事先锁住。          
    - pthread_cond_wait内部：对参数解锁，然后等待条件变量被激活
    - pthread_cond_wait内部：一旦条件变量被激活，当前线程将被激活，对参数上锁，然后从pthread_cond_t调用退出。

 >>>> missing wakeup signal -- why calling pthread_cond_singal must need to locking mutex.

    - the first situation   

            Process A                             Process B
            
            pthread_mutex_lock(&mutex);
            while (condition == FALSE) {
            
                                                  condition = TRUE;
                                                  pthread_cond_signal(&cond);
            
              pthread_cond_wait(&cond, &mutex);
            }
            
            pthread_mutex_unlock(&mutex)

         !!! The condition is now TRUE, but Process A is stuck waiting on the condition variable - it missed the wakeup signal. 
             If we alter Process B to lock the mutex:

            Process A                             Process B
            
            pthread_mutex_lock(&mutex);
              while (condition == FALSE) {
              pthread_cond_wait(&cond, &mutex);
            }
            pthread_mutex_unlock(&mutex)

                                                  pthread_mutex_lock(&mutex);
                                                  condition = TRUE;
                                                  pthread_cond_signal(&cond);
                                                  pthread_mutex_unlock(&mutex)
            


 >>>>> spurious wakeup -- 

    - the first situation : 

            Process A                             Process B

                                                  pthread_mutex_lock(&mutex);
                                                  pthread_cond_signal(&cond); // missing
                                                  pthread_mutex_unlock(&mutex)

            pthread_mutex_lock(&mutex);
            pthread_cond_wait(&cond, &mutex);
            pthread_mutex_unlock(&mutex)

        !!!! the signal from process B will do nothing, but process A will forever block.


    - the second situation 

  

            Process A                             Process B                              Process C
        
        phtread_mutex_lock(&mutex)
        phtread_cond_wait(&cond, &mutex)
                                            pthread_mutex_lock(&mutex)
                                            pthread_cond_wait(&cond, &mutex)
                                                                                      pthread_mutex_lock(&mutex)
                                                                                      m_message_queue(msg);
                                                                                      pthread_cond_boardcast(&cond, &mutex)
                                                                                      pthread_mutex_unlock(&mutex)
        msg = m_message_queue.front();
        msg = m_message_queue.pop_front();
        pthread_mutex_unlock(&mutex)
                                            msg = m_message_queue.front(); // !!!!!!!
                                            msg = m_message_queue.pop_front();
                                            pthread_mutex_unlock(&mutex)




        segment fault.


    - the three situation
      
        x is global variable....

            Process A                             Process B                              Process C
    
         while(0 < x < 5) 
           pthread_cond_wait
                                              while(10 < x < 15) 
                                                pthread_cond_wait

                                                                                           x = 0;
                                                                                        pthread_cond_singnal()
                                                                                           x = 2;
                                                                                        pthread_cond_singnal()
                                                                                           x = 5;
                                                                                        pthread_cond_singnal()
                                                                                           x = 10;
                                                                                        pthread_cond_singnal()
                                                                                           x = 12;
                                                                                        pthread_cond_singnal()


*/

namespace dehao {

// wrapper for condition_variable
class Cond {
  pthread_cond_t m_cond;
  Mutex *m_waiter_mutex;

  void operator=(Cond &C);
  Cond(const Cond &C);

 public:
  Cond() : m_waiter_mutex(NULL) {
    int r = pthread_cond_init(&m_cond, NULL);
    assert(r == 0);
  }

  virtual ~Cond() { 
    pthread_cond_destroy(&m_cond); 
  }

  int Wait(Mutex &mutex)  { 
    // make sure this cond is used with one mutex only
    assert(m_waiter_mutex == NULL || m_waiter_mutex == &mutex);
    m_waiter_mutex = &mutex;

    assert(mutex.is_locked());

    mutex._pre_unlock();
    int r = pthread_cond_wait(&m_cond, &mutex.m_lock);
    mutex._post_lock();
    return r;
  }

  /*
  int WaitUntil(Mutex &mutex, utime_t when) {
    // make sure this cond is used with one mutex only
    assert(m_waiter_mutex == NULL || m_waiter_mutex == &mutex);
    m_waiter_mutex = &mutex;

    assert(mutex.is_locked());

    struct timespec ts;
    when.to_timespec(&ts);

    mutex._pre_unlock();
    int r = pthread_cond_timedwait(&m_cond, &mutex.m_lock, &ts);
    mutex._post_lock();

    return r;
  }

  int WaitInterval(Mutex &mutex, utime_t interval) {
    utime_t when = ceph_clock_now();
    when += interval;
    return WaitUntil(mutex, when);
  }

  template<typename Duration>
  int WaitInterval(Mutex &mutex, Duration interval) {
    ceph::real_time when(ceph::real_clock::now());
    when += interval;

    struct timespec ts = ceph::real_clock::to_timespec(when);

    mutex._pre_unlock();
    int r = pthread_cond_timedwait(&m_cond, &mutex.m_lock, &ts);
    mutex._post_lock();

    return r;
  }
  */

  int SloppySignal() { 
    int r = pthread_cond_broadcast(&m_cond);
    return r;
  }
  int Signal() { 
    // make sure signaler is holding the waiter's lock.
    assert(m_waiter_mutex == NULL || m_waiter_mutex->is_locked());

    int r = pthread_cond_broadcast(&m_cond);
    return r;
  }
  int SignalOne() { 
    // make sure signaler is holding the waiter's lock.
    assert(m_waiter_mutex == NULL || m_waiter_mutex->is_locked());

    int r = pthread_cond_signal(&m_cond);
    return r;
  }
  int SignalAll() { 
    // make sure signaler is holding the waiter's lock.
    assert(m_waiter_mutex == NULL || m_waiter_mutex->is_locked());

    int r = pthread_cond_broadcast(&m_cond);
    return r;
  }
};

/**
 * context to signal a cond
 *
 * Generic context to signal a cond and store the return value.  We
 * assume the caller is holding the appropriate lock.
 */
class C_Cond : public Context {
  Cond *cond;   ///< Cond to signal
  bool *done;   ///< true if finish() has been called
  int *rval;    ///< return value
public:
  C_Cond(Cond *c, bool *d, int *r) : cond(c), done(d), rval(r) {
    *done = false;
  }
  void finish(int r) override {
    *done = true;
    *rval = r;
    cond->Signal();
  }
};

/**
 * context to signal a cond, protected by a lock
 *
 * Generic context to signal a cond under a specific lock. We take the
 * lock in the finish() callback, so the finish() caller must not
 * already hold it.
 */
class C_SafeCond : public Context {
  Mutex *lock;    ///< Mutex to take
  Cond *cond;     ///< Cond to signal
  bool *done;     ///< true after finish() has been called
  int *rval;      ///< return value (optional)
public:
  C_SafeCond(Mutex *l, Cond *c, bool *d, int *r=0) : lock(l), cond(c), done(d), rval(r) {
    *done = false;
  }
  void finish(int r) override {
    lock->lock();
    if (rval)
      *rval = r;
    *done = true;
    cond->Signal();
    lock->unlock();
  }
};

/**
 * Context providing a simple wait() mechanism to wait for completion
 *
 * The context will not be deleted as part of complete and must live
 * until wait() returns.
 */
class C_SaferCond : public Context {
  Mutex lock;   
  Cond cond;    
  bool done;    
  int rval; 
public:
  C_SaferCond() : lock("C_SaferCond"), done(false), rval(0) {}

  explicit C_SaferCond(const std::string &name) : lock(name), done(false), rval(0) {}

  void finish(int r) override { complete(r); }

  /// We overload complete in order to not delete the context
  void complete(int r) override {
    // std::lock_guard l(lock);
    Mutex::Locker l(lock);
    done = true;
    rval = r;
    cond.Signal();
  }

  int wait() {
    // std::lock_guard l(lock);
    Mutex::Locker l(lock);
    while (!done)
      cond.Wait(lock);
    return rval;
  }

  /// Wait until the \c secs expires or \c complete() is called
  /*
  int wait_for(double secs) {
    utime_t interval;
    interval.set_from_double(secs);
    std::lock_guard l{lock};
    if (done) {
      return rval;
    }
    cond.WaitInterval(lock, interval);
    return done ? rval : ETIMEDOUT;
  }
  */
};

}


#endif


// back up 
// https://www.zhihu.com/question/24116967
// https://stackoverflow.com/questions/4544234/calling-pthread-cond-signal-without-locking-mutex


