#include "../../leetcode/common.h"
#include <iostream>
#include <thread>
#include "cond.h"
#include <unistd.h>

using namespace dehao;

void test_condition_variable() {

  C_SaferCond test_cond;
  C_SaferCond test_cond1;


  auto thread_func = [](C_SaferCond& cond) {
    for(int i = 0; i < 1000; i++) {
      cout << "k";
    }
    cout << endl;
    cond.complete(0);
  };

  std::thread th1([&test_cond, &test_cond1](){
    test_cond1.wait();
    for(int i = 0; i < 1000; i++) {
      cout << "z";
    }
    cout << endl;
    test_cond.complete(0);
  });
  

  std::thread th2([&thread_func, &test_cond1]() {thread_func(test_cond1);});

  test_cond.wait();

  for(int i = 0; i < 1000; i++) {
    cout << "x";
  }
  cout << endl;

  th1.join();
  th2.join();
}




int main() {

  test_condition_variable();

  return 0;
}
