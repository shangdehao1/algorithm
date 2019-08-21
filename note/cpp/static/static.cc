#include <iostream>
#include <assert.h>
#include <string>

using namespace std;

// construction : when first call lambda function, create static object.
// destruction  : when main function exists, destruct static object.
void test_static_variable_in_function() 
{
  {
    class test_static {
     public:
      test_static() { std::cout << "test_static_variable_in_function : construction..." << std::endl; }
      ~test_static() {std::cout << "test_static_variable_in_function : destruction..." << std::endl; }
      uint32_t m_index{0};
    };

    auto function = [](int i) {
      static test_static xxx;
      assert(xxx.m_index == i); 
      xxx.m_index = i + 1;
    };

    for (int i = 0; i < 1000; i++) {
      function(i);
    }
  }
}

// =========================================

class static_object 
{
public:
  static_object()  {std::cout << "static_object : construction..." << std::endl; }
  ~static_object() {std::cout << "static_object : destruction...." << std::endl; }
  string m_index;
};

// how do data member construct or destruct data member ?
// create : call static method at the first time calling.

class test_static 
{
public:
  test_static() {}
  ~test_static() {}

  void set_data(string p) {
    m_data_1 = p;
  }
  
  void non_static_function_access_static_data_member(string m) {
   // m_object.m_index = m;
  }

  static void static_function_access_static_data_member(string m) {
    m_object.m_index = m;
  }

//  static void set_static_member (string m) {
//    m_data_2 = m;
//  }

public:
  string m_data_1;
  static static_object m_object;
};

static_object test_static::m_object;

void test_static_method_in_class () {
  test_static temp;
  temp.non_static_function_access_static_data_member("shangdehao");
  test_static::static_function_access_static_data_member("shangdehao");

}


int main () {

  cout << "main begin..." << endl;

  test_static_variable_in_function();
  test_static_method_in_class (); 


  cout << "main over..." << endl;
  return 0;
}

