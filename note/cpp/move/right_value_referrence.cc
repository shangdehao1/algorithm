#include <iostream> 
#include <assert.h>
#include <string>
#include <utility>

using namespace std;

/*

=========>>>>> right-value-referrence. <<<<<<====================

(std::string&)&& ref // ref is std::string&
(const std::string&)&& ref // ref is const std::string&
(std::string&&)&& ref // ref is std::string&&
(const std::string&&)&& ref // ref is const std::string&&

*/


namespace _test_left_or_right_value {

string information(string&& t) {
  return "right-value";
}

string information(string& t) {
  return "left-value";
}

template<typename T>
string print_direct(T&& t) {
  return information(t);
}

template<typename T>
string print_forward(T&& t) {
  return information(std::forward<T>(t));
}

template<typename T> 
string print_move(T&& t) {
  return information(std::move(t));
}

}


void test_left_or_right_value() {
  using namespace _test_left_or_right_value;

  {
    string t;
    assert(print_direct(t) == "left-value");
  }

  {
    // notice : there are big difference 
    assert(print_direct("") == "right-value");
    assert(print_direct(string("----")) == "left-value");
  }

  {
    string t;
    assert(print_forward(t) == "left-value");
  }

  {
    assert(print_forward("") == "right-value");
  }

  {
    string t;
    assert(print_move(t) == "right-value");
  }

  {
    assert(print_move("") == "right-value");
  }

}


void test_type() {

  string temp1("shangdehao");

}


void test_some_conclusion() {
  string xxx("shangdehao");

  string& yyy = xxx;
  string& zzz = yyy;
  
  assert(xxx  == "shangdehao");
  assert(yyy  == "shangdehao");
  assert(zzz  == "shangdehao");
}




int main() {

  test_type();
  test_some_conclusion();

  test_left_or_right_value();

  return 0;
}




