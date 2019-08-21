#include <memory>
#include <string>
#include <iostream>
#include <assert.h>


using namespace std;

namespace dehao_weak {

  class test_weak {
  public:
    test_weak() {}
    test_weak(string m) : m_data(m){
    }

    ~test_weak() {
      cout << "destruction" << endl;
    }

    test_weak(const test_weak& other) : m_data(other.m_data) {
      cout << "copy construction " << endl;
    }

    test_weak(test_weak&& other) : m_data(std::move(other.m_data)) {
      assert(other.m_data.size() == 0);
      cout << "move construction " << endl;
    }

    string m_data; 
  };

};

void test_weak_ptr_basic_method () 
{
  using namespace dehao_weak;

  // test construction
  {
    cout << "========================" << endl;

    // weak default construction
    {
      shared_ptr<test_weak> temp = make_shared<test_weak>("shangdehao");

      weak_ptr<test_weak> xx;

      assert(xx.use_count() == 0);
      assert(xx.expired() == true);
      assert(xx.lock() == nullptr);
    }

    // weak construction which can receive shared_ptr parameter.
    {
      shared_ptr<test_weak> temp = make_shared<test_weak>("shangdehao");
      weak_ptr<test_weak> xx = temp;

      assert(temp.use_count() == 1);
      assert(xx.use_count() == 1);
    }

    // weak copy construction
    {
      shared_ptr<test_weak> temp = make_shared<test_weak>("shangdehao");
      weak_ptr<test_weak> xx(temp);
      weak_ptr<test_weak> yy(xx);

      assert(temp.use_count() == 1);
      assert(xx.use_count() == 1);
      assert(yy.use_count() == 1);
    }

    // lock method will return shared_ptr which will have ownship for resources.
    {
      shared_ptr<test_weak> temp = make_shared<test_weak>("shangdehao");
      weak_ptr<test_weak> xx(temp);

      shared_ptr<test_weak> yy = xx.lock();
      
      assert(yy != nullptr);
      assert(temp.use_count() == 2);
      assert(xx.use_count() == 2);
      assert(yy.use_count() == 2);
      assert(yy.get() == temp.get());

      yy.reset();
      assert(temp.use_count() == 1);
      assert(xx.use_count() == 1);
      assert(xx.expired() == false);
      assert(yy.use_count() == 0);
      
    }

    // expired
    {
      shared_ptr<test_weak> temp = make_shared<test_weak>("shangdehao");
      weak_ptr<test_weak> xx(temp);

      assert(temp.use_count() == 1);
      assert(xx.use_count() == 1);
      assert(xx.expired() == false);

      temp.reset();
      assert(temp.use_count() == 0);
      assert(xx.use_count() == 0);
      assert(xx.expired() == true);
    }
    
  }

}

void test_weak_situation() 
{
  {
    class test_shared_b;
    class test_shared_a
    {
    public:
        shared_ptr<class test_shared_b> m_data_shared_b;
    };
    
    class test_shared_b
    {
    public:
        shared_ptr<class test_shared_a> m_data_shared_a;
    };

    weak_ptr<test_shared_a> check_a; 
    weak_ptr<test_shared_b> check_b;
    {
      auto tempa = make_shared<test_shared_a>(); 
      auto tempb = make_shared<test_shared_b>();

      assert(tempa.use_count() == 1);
      assert(tempb.use_count() == 1);
    
      tempa->m_data_shared_b = tempb;
      tempb->m_data_shared_a = tempa;

      assert(tempa.use_count() == 2);
      assert(tempb.use_count() == 2);
      
      check_a = tempa;
      check_b = tempb;
    }
      
    assert(check_a.use_count() == 1); // memory leak
    assert(check_b.use_count() == 1); // memory leak
  }

  {
    class test_shared_b;
    class test_shared_a
    {
    public:
        weak_ptr<class test_shared_b> m_data_weak_b;
    };
    
    class test_shared_b
    {
    public:
        weak_ptr<class test_shared_a> m_data_weak_a;
    };

    weak_ptr<test_shared_a> check_a; 
    weak_ptr<test_shared_b> check_b;
    {
      auto tempa = make_shared<test_shared_a>(); 
      auto tempb = make_shared<test_shared_b>();

      assert(tempa.use_count() == 1);
      assert(tempb.use_count() == 1);
    
      tempa->m_data_weak_b = tempb;
      tempb->m_data_weak_a = tempa;

      assert(tempa.use_count() == 1);
      assert(tempb.use_count() == 1);
      
      check_a = tempa;
      check_b = tempb;
    }
      
    assert(check_a.use_count() == 0);
    assert(check_b.use_count() == 0);
  }
}

int main() {

  test_weak_ptr_basic_method();
  test_weak_situation();

  return 0;
}




