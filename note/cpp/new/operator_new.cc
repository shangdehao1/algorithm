#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

namespace _test_operator {

class X
{
public:

  X() { 
    m_step2 = "construction";
  }

  ~X() { 
    m_step3 = "destruction";
  }

  void* operator new(size_t size) {
    assert(size == sizeof(X));
    m_step1 = "operator-new-1";
    return ::operator new(size);
  }

  void* operator new(size_t size, string str) {
    assert(size == sizeof(X));
    m_step1 = "operator-new-2";
    return ::operator new(size);
  }

  void operator delete(void* pointee) {
    m_step4 = "operator-delete"; 
    ::operator delete(pointee);
  }

  static void cleanup_static() {
    m_step1.clear();  
    m_step2.clear();  
    m_step3.clear();  
    m_step4.clear();  
  }

  static string m_step1;
  static string m_step2;
  static string m_step3;
  static string m_step4;
};

string X::m_step1 = "";
string X::m_step2 = "";
string X::m_step3 = "";
string X::m_step4 = "";

}

void test_operator() 
{
  using namespace _test_operator;

  {
    X::cleanup_static();

    auto temp = new X;
    delete temp;

    assert(X::m_step1 == "operator-new-1");  
    assert(X::m_step2 == "construction");
    assert(X::m_step3 == "destruction");
    assert(X::m_step4 == "operator-delete");

    X::cleanup_static();
  }

  {
    X::cleanup_static();

    auto temp = new("123") X;
    delete temp;

    assert(X::m_step1 == "operator-new-2");  
    assert(X::m_step2 == "construction");
    assert(X::m_step3 == "destruction");
    assert(X::m_step4 == "operator-delete");

    X::cleanup_static();
  }

}

// ============================================================

namespace _test_placement 
{
  class XX {
   public:
    XX() { 
      m_data = "default-construction";
    }
  
    XX(int i) { 
      m_data = "singnal-param-construction";
    }
  
    ~XX() {
    }
  
    string m_data;
  };
}

void test_placement() 
{
  using namespace _test_placement;

  {
    char temp[sizeof(XX)];

    XX* p = new (temp)XX(1);

    assert(p->m_data == "singnal-param-construction");
  }

  {
    char temp[sizeof(XX)];

    XX* p = new (temp)XX;

    assert(p->m_data == "default-construction");
  }

}


int main()
{
    test_operator();
    test_placement_new();

    return 0;
}
