#ifndef MUTEX_H
#define MUTEX_H

#include <string>
#include <pthread.h>
#include <mutex>
#include <assert.h>

namespace dehao {

class Mutex {
private:
  std::string m_lock_name;
  int id;
  bool m_support_recursive;
  pthread_mutex_t m_lock;
  int m_locked_times;
  pthread_t m_locked_by;
  bool m_error_check;

  // don't allow copying.
  void operator=(const Mutex &M);
  Mutex(const Mutex &M);

public:

  Mutex(const std::string n = "", bool r = false, bool ec = false) :
    m_lock_name(n), id(-1), m_support_recursive(r), m_error_check(ec), m_locked_times(0), m_locked_by(0)
  {
    if (m_support_recursive) {
      // Mutexes of type PTHREAD_MUTEX_RECURSIVE do all the same checks as
      // mutexes of type PTHREAD_MUTEX_ERRORCHECK.
      pthread_mutexattr_t attr;
      pthread_mutexattr_init(&attr);
      pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
      pthread_mutex_init(&m_lock,&attr);
      pthread_mutexattr_destroy(&attr);
    }
    else if (m_error_check) {
      // If the mutex type is PTHREAD_MUTEX_ERRORCHECK, then error checking
      // shall be provided. If a thread attempts to relock a mutex that it
      // has already locked, an error shall be returned. If a thread
      // attempts to unlock a mutex that it has not locked or a mutex which
      // is unlocked, an error shall be returned.
      pthread_mutexattr_t attr;
      pthread_mutexattr_init(&attr);
      pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_ERRORCHECK);
      pthread_mutex_init(&m_lock, &attr);
      pthread_mutexattr_destroy(&attr);
    }
    else {
      // If the mutex type is PTHREAD_MUTEX_DEFAULT, attempting to recursively
      // lock the mutex results in undefined behavior. Attempting to unlock the
      // mutex if it was not locked by the calling thread results in undefined
      // behavior. Attempting to unlock the mutex if it is not locked results in
      // undefined behavior.
      pthread_mutex_init(&m_lock, NULL);
    }
  }


  ~Mutex() {
    assert(m_locked_times == 0);
    pthread_mutex_destroy(&m_lock);
  }

  bool is_locked() const {
    return (m_locked_times > 0);
  }

  bool is_locked_by_me() const {
    return m_locked_times > 0 && m_locked_by == pthread_self();
  }

  bool try_lock() {
    int r = pthread_mutex_trylock(&m_lock);
    if (r == 0) {
      _post_lock();
    }
    return r == 0;
  }

  void lock()
  {
    int r = pthread_mutex_lock(&m_lock);
    assert(r == 0);
    _post_lock();
  }

  void _post_lock() {
    if (!m_support_recursive) {
      assert(m_locked_times == 0);
      m_locked_by = pthread_self();
    };
    m_locked_times++;
  }

  void _pre_unlock() {
    assert(m_locked_times > 0);
    --m_locked_times;
    if (!m_support_recursive) {
      assert(m_locked_by == pthread_self());
      m_locked_by = 0;
      assert(m_locked_times == 0);
    }
  }

  void unlock()
  {
    _pre_unlock();
    int r = pthread_mutex_unlock(&m_lock);
    assert(r == 0);
  }

  std::string get_lock_name() {
    return m_lock_name;
  }

  friend class Cond;

public:
  typedef std::lock_guard<Mutex> Locker;
};

};

#endif
