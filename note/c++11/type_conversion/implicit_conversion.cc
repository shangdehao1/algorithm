#include <iostream>
#include <string>
#include <assert.h>
#include <functional>

using namespace std;


class A {};

class B {
public:
  string m_data;
  // conversion from A (constructor):
  B(){};
  B (const A& x) {
    m_data = "single-param-construction";
  }

  // conversion from A (assignment):
  B& operator= (const A& x) {
    m_data = "assignment-operator";
    return *this;
  }

  // conversion to A (type-cast operator)
  operator A() {
    m_data = "() operator";
    return A();
  }
};

void test_single_param_conversion() {

  {
    A a;
    B b(a);
    assert(b.m_data == "single-param-construction");
  }

  {
    A a;
    B b = a;
    assert(b.m_data == "single-param-construction");
  }

  {
    auto function = [](B b) {
      assert(b.m_data == "single-param-construction");
    };

    A a; 
    function(a);
  }

  {
    A a;
    auto t = static_cast<B>(a);
    assert(t.m_data == "single-param-construction");

  }

}

void test_assignment_conversion () {
  {
    A a;
    B b;

    b = a; 
    assert(b.m_data == "assignment-operator");
  }
}

void test_operator_conversion() {

  // C conversion : 1
  {
    B b;
    (A)b;
    assert(b.m_data == "() operator");
  }

  // C conversion : 2
  {
    B b;
    auto t = A(b);
    assert(b.m_data == "() operator");
  }

  // static_cast : 3
  {
    B b;
    auto t = static_cast<A>(b);
    assert(b.m_data == "() operator");
  }

  {
    // compiler error
    // B b;
    // auto t = dynamic_cast<A*>(b);
    // assert(b.m_data == "() operator");
  }


}

// ============

int main() {
  test_single_param_conversion();
  test_assignment_conversion();
  test_operator_conversion();

  return 0;
}




