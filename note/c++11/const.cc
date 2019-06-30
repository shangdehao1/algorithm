#include  <iostream>
#include <string>
#include <assert.h>

// ================= some conclusion =======================
/*
 * const method can't modify general data member....
 * const method can modify mutable data member 
 *
 * non-const object can call const-method and non-const-method.
 * if one method is over-rided, priority to call non-const method.
 *
 * const-object just can call const method, and forbid to call non-const method.
 */

using namespace std;

namespace dehao_const {

  class test_class {
  public:
    test_class(string m) : m_data(m) {}
    ~test_class() {}

    string output_nonconst () {
      return "output_nonconst";
    }

    string output_const() const {
      return "output_const";
    }

    void set_data_nonconst (const string& m) {
      m_data = m;
      m_data_0 = m + "-----";
    }

    // const method can't modify general data member....
    // const method can modify mutable data member 
    void set_data_const(const string& m) const {
      // m_data = m; 
      m_data_0 = m + "------";
    }

    string test_overload() {
      return "non-const-test-overload";
    }

    string test_overload() const {
      return "const-test-overload";
    }

    string m_data;
    mutable string m_data_0;
  };
}


void test_const_class_method() 
{
  using namespace dehao_const; // test_class;

  // non-const object can call const-method and non-const-method.
  // if one method is over-rided, priority to call non-const method.
  {
    test_class temp("shangdehao");

    assert(temp.output_nonconst() == "output_nonconst");
    assert(temp.output_const() == "output_const");

    temp.set_data_const("zzr");
    temp.set_data_nonconst("zzr");

    assert(temp.test_overload() == "non-const-test-overload");
  }

  // const-object just can call const method, and forbid to call non-const method.
  {
    const test_class temp("shangdehao");
    
    //assert(temp.output_nonconst() == "output_nonconst");

    assert(temp.output_const() == "output_const");
    temp.set_data_const("zzr");
  }
}


int main() {

  test_const_class_method();
}
