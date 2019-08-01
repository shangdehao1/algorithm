#include <iostream>
#include <assert.h>
#include <stdio.h>



using namespace std;

namespace test_empty {

class x {};
class y : public virtual x {};
class z : public virtual x {};
class k : public x {};
class a : public y, public z {};

}


void test_empty_object_size() {
  using namespace test_empty;

  assert(sizeof(x) == 1);

  assert(sizeof(y) == 8);
  assert(sizeof(z) == 8);
  assert(sizeof(k) == 1);

  assert(sizeof(a) == 16);
}

// =============================

namespace test_vptr_size {

class x {
public:  
  virtual void output() {}
};

class y : public x {
public:
  virtual void output1() {}
};

class z : virtual public y {
public:
  virtual void output1() {}
};

}

void test_vptr() {
  using namespace test_vptr_size;

  assert(sizeof(x) == 8);
  assert(sizeof(y) == 8);
  assert(sizeof(z) == 8);


  x tempx;
  y tempy;
  z tempz;
  assert(sizeof(tempx) == 8);
  assert(sizeof(tempy) == 8);
  assert(sizeof(tempz) == 8);

}

namespace _test_data_member_offset {
  class point {
    public:
    int x;
    int y;
    int z;
    int k;
    virtual ~point(){}
  };
}


void test_data_member_offset() {
  using namespace _test_data_member_offset;
  
  assert(sizeof(int) == 4);
  assert(sizeof(void*) == 8);

  assert(sizeof(point) == (4*sizeof(int) + sizeof(void*)));

  cout << &point::x << endl;
  cout << &point::y << endl;
  cout << &point::z << endl;
  cout << &point::k << endl;


  printf("%d\n", &point::x); // 8
  printf("%d\n", &point::y); // 12
  printf("%d\n", &point::z); // 16
  printf("%d\n", &point::k); // 20

  point temp;

  printf("%p\n", &temp.x);
  printf("%p\n", &temp);
  printf("%p\n", &point::x);

}


namespace _test_param_list {

class output {
public:  
  output(int i) {}
  string who_am_i() { return "external-output"; }
};


class point {
public:

  // note : !!!! param output will be explarat to external output...
  string print_information(output a) {
    return a.who_am_i();
  }
  

  class output {
  public:  
    output(int i) {}
    string who_am_i() { return "internal-output"; }
  };
};

}


void test_param_list() {
  using namespace _test_param_list;

  
  point temp;
  assert(temp.print_information(0) == "external-output");
  cout << temp.print_information(0) << endl;;
}





int main () {

  test_empty_object_size();  
  test_vptr();
  test_data_member_offset();
  test_param_list();

  return 0;
}

