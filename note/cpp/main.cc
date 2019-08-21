#include <iostream>
#include "../../leetcode/common.h"


/* this source code is that c++11 introduce some new features */

using namespace std;


namespace test_class {
  class copy_class {
  };
};



// ====================================

// c++11 support uniform initialization
void test_initializer_list() 
{
  // build-in tye support
  {
    int a {1};
    int b {2};
    double c{3.22};
    assert(a == 1 && b == 2 && c == 3.22);
  }
  
  // stl support
  {
    vector<int> temp{1,2,3,4,5};
    assert(temp.size() == 5);
    set<int> test_set{1,2,3,4,5,6,1};
    unordered_map<int, int> temp_unordered_map{{1, 2}, {2, 3}, {3, 4}};
    list<int> temp_list{1,2,3,4,5,6};
  }

  // initializer list support
  {
      class test_init_list {
      public:
          test_init_list(const std::initializer_list<int>& items)
              : m_data(items){}
      
          std::vector<int> m_data;
      };

      test_init_list temp{0, 1, 2, 3, 4, 5};

      for (int i = 0; i < temp.m_data.size(); i++) {
        assert(i == temp.m_data[i]); 
      }
  }

  // non-initializer also can support
  {
    class test_class {
      public:
      test_class(int x, int y, int z) : xx(x), yy(y), zz(z) {}
      int xx, yy, zz;
    };

    test_class temp{1, 2, 3};
    assert(temp.xx == 1);
    assert(temp.yy == 2);
    assert(temp.zz == 3);
  
  }

}

// =========================================

// c++11 perfectly support (auto + &)
void test_auto () 
{
  auto check_vector = [](vector<int>& data) {
    for(int i = 0; i < data.size(); i++) {
      if (data[i] != i) return false;
    }
    return true;
  };
  
  // auto default will copy function to create temp object.
  {
    vector<int> temp{0, 1, 2, 3, 4, 5, 6};

    // will call copy construction
    for (auto i : temp) {
      i = 123;
    }

    assert(check_vector(temp) == true);
  
    for (auto& i : temp) {
      i = 123;
    }

    for (auto i : temp) {
      assert(i == 123);
    }
  }

}

// =======================================

void test_enum() 
{
  // the following code will lead to redeclaration
  // compiler error : redeclaration of data_1
  {
    /*
    enum test_1 {
      data_1,
      data_2
    };

    enum test_2 {
      data_1,
      data_2
    };
    */
  }

  // using enum class to slove redeclaration
  {
    enum class test_1 {
      data_1,
      data_2
    };

    enum class test_2 {
      data_1,
      data_2
    };

    // now enum value isn't global, and it have namespace.
    test_1 x = test_1::data_1;
    test_1 y = test_1::data_2;

    test_2 z = test_2::data_1;
    test_2 k = test_2::data_2;

  
    // different enum type can't operate !!!!
    // if (x == z) cout << "this sentence can't pass compiler..." << endl;

    // perfect
    if (x == y) cout << "this sentencec can pss compiler..." << endl;
  }

}

// =============================================

void test_static_assert() 
{
  // compiler can pass
  static_assert(sizeof(int) == 4);

  // sentence below will lead to compiler error !!!!!
  // static_assert(sizeof(int) == 5);
}

// ===========================================

void test_construction_call_each_other () 
{
  // compared to init method, there are two good advantage as below : 
  //  - init method : construction, then assign operation. 
  //     if internal object don't supprot assignment, this method don't work.
  //  - For some specific data memeber, for refference or const data.
  //  - how to ensure just be called one time...

  {
    class test_class {
    public:
      test_class() : test_class(1) { output(0); }
      test_class(int x) : test_class(x, 2) { output(1); }
      test_class(int x, int y) : test_class(x, y, 3) { output(2); }
      test_class(int x, int y, int z) : m_data_1(x), m_data_2(y), m_data_3(z) { output(3); }

      void output(int i) {cout << "construction " << i << endl;}

      int m_data_1;
      int m_data_2;
      int m_data_3;
    };

    test_class temp;
  } 

}

// ===========================================

void test_final() 
{
  // finnal function can't be override.
  // compiler error : overriding final function
  {
    /*
    class parent {
    public:
      virtual string get_name() final { return "i am parent class"; }
    };

    class child : public parent {
    public:
      virtual string get_name() { return "i am child class"; }
    };
    */
  }


  // final class can't be used as base class.
  // complier error : cannot derive from final base 
  {
    /*
    // class parent {
    class parent final {
    public:
      virtual string get_name() { return "i am parent class"; }
    };

    class child : public parent {
    public:
      virtual string get_child_name() { return "i am child class"; }
    };
    */
  }
}

// ============================================

// override will explictly tell gcc that current method is override of base method...
void test_override () 
{
  {
    class parent {
      public: 
        virtual string get_name() { return "i am parent class"; }
        virtual string hello() const {return "hello parent"; }
    };

    class child : public parent {
      public :
        
        // explictly tell compiler that this method is override base method.
        virtual string get_name() override { return "i am child class"; }

        // compiler think this is new method which is defined by child class.
        virtual string get_name() const { return "i am child class"; }
        
        // override tell complier that this method is override of base method.
        // but can't find this mehod in parent class. 
        // error : test_override()::parent::get_name()’ marked ‘override’, but does not override
        // virtual string hello() override {return "hello parent"; }
    };

  }
}

// ============================================
void test_directly_init_class_data_member() 
{

  //  if there is initial action at initialization list, will just use this. 
  //  if there don't exist initial action at initialization list, will just use directly initial action.

  {
    class data_member {
      public:
          data_member(int i) : i(i) {
              std::cout << "data_member(" << i << ")" << std::endl;
          }
      
          data_member(const data_member& other) : i(other.i) {
              std::cout << "copy data_member(" << i << ")" << std::endl;
          }
      
          data_member& operator = (const data_member& other) {
              i = other.i;
              std::cout << "= data_member(" << i << ")" << std::endl;
              return *this;
          }
      
      int i;
    };
  
  
    class test_class {
    public:
      test_class() {}
      test_class(int xx) : m_data(xx) {}
  
      data_member m_data{12345}; // this is directly initial action, and less lower priority than initialization list. !!!!!
    };
  
    // -----

    test_class temp1;
    assert(temp1.m_data.i == 12345);
  
    test_class temp2(111);
    assert(temp2.m_data.i == 111);
  }
  

}

// ============================

void test_default_and_delete() 
{
  // default : c++ complier must create some function, for example default construction, copy construction, and so on.
  // delete : c++ complier be forbided to create some function, for example copy construction.
  {
    class test {
      public:
      test(int i) : m_data(i) {}
      test() = default;
      test(test& other) = delete;
      int m_data;
    };

    test x(100);
    assert(x.m_data == 100);

    test y;
    cout << endl << "default : " << y.m_data << endl;
    
    // can't pass compiler
    // test z(x);
  }
}

// ===========================

namespace dehao {
  int size() { return sizeof(int) + sizeof(double);}
  constexpr int const_size() { return sizeof(int) + sizeof(double); }
};

void test_constexpr() 
{
  {
    int xxxx[dehao::size()];
  
    int yyyy[dehao::const_size()];
  }

}

// ================ lambda function and function object =================

namespace test_lambda 
{
  void printf(vector<string>& data, std::function<bool(string)> handle) {
    for (auto i : data) {
      handle(i); 
    }
  }
};


void test_lambda_and_function() {

  std::function<bool(string)> handle_temp = [](string data) {
    cout << data << endl;
    return true;
  };

  vector<string> testing{"this", "is", "lambda", "testing"};

  // actual paramter : lambda function object
  //                 : function type
  test_lambda::printf(testing, handle_temp);

}


// ====================================================


int main() {

  test_initializer_list();
  test_auto();
  test_enum();
  test_static_assert();
  test_construction_call_each_other();
  test_override();
  test_directly_init_class_data_member();
  test_default_and_delete();
  test_constexpr();
  test_lambda_and_function();

  return 0;
}









// backup : https://www.jianshu.com/p/d0a98e0eb1a8


