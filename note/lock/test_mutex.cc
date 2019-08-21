#include "../../leetcode/common.h"
#include "mutex.h"
#include <thread>
#include <unistd.h>





void test_exclusive_lock() {

  dehao::Mutex g_lock;

  auto thread_function_lock = [&g_lock] (int times, bool is_x) {
    {
      dehao::Mutex::Locker lock(g_lock);

      for (int i = 0; i < times; i++) {
        if (is_x) cout << "x";
        else cout << "y";
      }    
    }
  };
  
  auto thread_function_free = [] (int times, bool is_x) {
      for (int i = 0; i < times; i++) {
        if (is_x) cout << "*";
        else cout << ".";
      }    
  };

  {
    std::thread thread1([thread_function_lock](){ thread_function_lock(1000, true);});
    std::thread thread2([thread_function_lock](){ thread_function_lock(1000, false);});
    thread1.join();
    thread2.join();
  }

  cout << endl;

  {
    std::thread thread1([thread_function_free](){ thread_function_free(1000, true);});
    std::thread thread2([thread_function_free](){ thread_function_free(1000, false);});
    thread1.join();
    thread2.join();
  }
}


int main() {

  test_exclusive_lock();


  return 0;



}
