#include <iostream>
#include <string>
#include <assert.h>

using namespace std;


namespace test_operator {

class X
{
public:

    X() { 
      cout << "step 2 : constructor" << endl; 
    }

    ~X() { 
      cout << "step 1 : destructor" << endl;
    }

    void* operator new(size_t size, string str) {
        cout << "step 1 : alloc memory using reload operator new." << endl;
        return ::operator new(size);
    }

    void operator delete(void* pointee)
    {
        cout<<"step 2 : delete memory"<<endl;
        ::operator delete(pointee);
    }
private:
    string m_data;
};

}


namespace test_placement {

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

void test_placement_new() {
  using namespace test_placement;

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
    test_placement_new();


    return 0;
}
