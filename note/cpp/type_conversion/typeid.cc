#include <string>
#include <vector>
#include <iostream>
#include <list>
#include <assert.h>
#include <typeinfo>

using namespace std;


void test_in_build_type () {

  // build-in type
  {
    assert(typeid(int).name() == string("i"));
    assert(typeid(unsigned int).name() == string("j")); 
    assert(typeid(long).name() == string("l")); 
    assert(typeid(long long).name() == string("x")); 
    assert(typeid(float).name() == string("f")); 
    assert(typeid(char).name() == string("c")); 
  }

  // pointer 
  {
    assert(typeid(int*).name() == string("Pi"));
    assert(typeid(unsigned int*).name() == string("Pj")); 
    assert(typeid(long*).name() == string("Pl")); 
    assert(typeid(long long*).name() == string("Px")); 
    assert(typeid(float*).name() == string("Pf")); 
    assert(typeid(char*).name() == string("Pc")); 
  }

  // referrence 
  // typeid wil remove referrence...!!!!!
  {
    assert(typeid(int&).name() == string("i"));
    assert(typeid(unsigned int&).name() == string("j")); 
    assert(typeid(long&).name() == string("l")); 
    assert(typeid(long long&).name() == string("x")); 
    assert(typeid(float&).name() == string("f")); 
    assert(typeid(char&).name() == string("c")); 
  }

  // stl
  {
    assert(typeid(vector<int>).name()  == string("St6vectorIiSaIiEE"));
    assert(typeid(vector<char>).name() == string("St6vectorIcSaIcEE"));
  }
}

// ============================ 

void test_class () {

  struct base0 {
  };

  struct child0 : public base0 {
  };

  struct base {
    virtual void ouput() {}
  };

  struct child : public base {
  };

  {
    assert(typeid(base0).name()  == string("Z10test_classvE5base0"));
    assert(typeid(child0).name() == string("Z10test_classvE6child0"));

    assert(typeid(base).name()  == string("Z10test_classvE4base"));
    assert(typeid(child).name() == string("Z10test_classvE5child"));
  }
  

  // typeid can't recognize polymorphic of pointer.
  {
    base0 o1;
    child0 o2;
    base0* k1 = &o1;
    base0* k2 = &o1;
    assert(typeid(k1).name()  == string("PZ10test_classvE5base0"));
    assert(typeid(k2).name()  == string("PZ10test_classvE5base0"));

    base xx;
    child yy;
    base* p1 = &xx;
    base* p2 = &yy;
    assert(typeid(p1).name()  == string("PZ10test_classvE4base"));
    assert(typeid(p2).name() ==  string("PZ10test_classvE4base"));
  }

  // typeid can recongize polymorephic of referrence.
  {
    child0 xx;
    base0& yy = xx;
    assert(typeid(yy).name()  == string("Z10test_classvE5base0"));
  
    child zz;
    base& kk = zz;
    assert(typeid(kk).name() == string("Z10test_classvE5child"));
  }
}




int main() {

  test_in_build_type();
  test_class();


  return 0;
}
