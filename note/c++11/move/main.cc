#include "../../leetcode/common.h"


namespace copy_construction {

class test_class_only_const_copy {
public:
  test_class_only_const_copy() {}
  test_class_only_const_copy(string x1, string x2) : m_data1(x1), m_data2(x2) {}
  ~test_class_only_const_copy() {}

  // =================== copy construction =======================
  
  // at most situations, the below format is encough.
  // it can accept const-object and non-const-object.
  test_class_only_const_copy(const test_class_only_const_copy& other) {
    m_data1 = other.m_data1;
    m_data2 = other.m_data2;
    cout << "copy construction function -- with const paramter.." << endl;
  }
  
private:
  string m_data1;
  string m_data2;
};

class test_class_only_non_const_copy {
public:
  test_class_only_non_const_copy() {}
  test_class_only_non_const_copy(string x1, string x2) : m_data1(x1), m_data2(x2) {}
  ~test_class_only_non_const_copy() {}

  // =================== copy construction =======================
  
  // at most situations, the below format is encough.
  // it can accept const-object and non-const-object.
  test_class_only_non_const_copy(test_class_only_non_const_copy& other) {
    m_data1 = other.m_data1;
    m_data2 = other.m_data2;
    cout << "copy construction function -- with non-const paramter.." << endl;
  }
  
private:
  string m_data1;
  string m_data2;
};

class test_class_both_copy {
public:
  test_class_both_copy() {}
  test_class_both_copy(string x1, string x2) : m_data1(x1), m_data2(x2) {}
  ~test_class_both_copy() {}

  // =================== copy construction =======================
  
  // at most situations, the below format is encough.
  // it can accept const-object and non-const-object.
  test_class_both_copy(test_class_both_copy& other) {
    m_data1 = other.m_data1;
    m_data2 = other.m_data2;
    cout << "copy construction function -- with const paramter.." << endl;
  }

  test_class_both_copy(const test_class_both_copy& other) {
    m_data1 = other.m_data1;
    m_data2 = other.m_data2;
    cout << "copy construction function -- with non-const paramter.." << endl;
  }
  
  void output_data_member() {
    cout << "non-const method ---> m_data1 : " << m_data1 << endl;
    cout << "non-const method ---> m_data2 : " << m_data2 << endl;
  }

  void output_data_member() const {
    cout << "const method ----> m_data1 : " << m_data1 << endl;
    cout << "const method ----> m_data2 : " << m_data2 << endl;
  }

private:
  string m_data1;
  string m_data2;
};

}

namespace assign_construction {

}


namespace dehao_move {

class test_move {
public:
  test_move() {}
  test_move(string x1, string x2) : m_data1(x1), m_data2(x2) {}
  ~test_move() {}

  // copy construction
  test_move(const test_move& other) {
    m_data1 = other.m_data1;
    m_data2 = other.m_data2;
    cout << "copy construction.." << endl;
  }

  // move construction
  test_move(test_move&& other) : m_data1(std::move(m_data1)), m_data2(std::move(m_data2)) {
    assert(other.m_data1.size() == 0);
    assert(other.m_data2.size() == 0);
    cout << "move construction.." << endl;
  }

  // assign operator
  test_move& operator=(const test_move& other) {
    m_data1 = other.m_data1;
    m_data2 = other.m_data2;
    cout << "assign operator..." << endl;
  }

  // move operator
  test_move& operator=(test_move&& other) {
    m_data1 = std::move(other.m_data1);
    m_data2 = std::move(other.m_data2);
    assert(other.m_data1.size() == 0);
    assert(other.m_data2.size() == 0);
  }

private:
  string m_data1;
  string m_data2;
};

}



void test_copy_construction() {

    using namespace copy_construction;
      
    {
      test_class_only_const_copy x1("xx11", "yy11");
      const test_class_only_const_copy x2("xx22", "yy22");

      // non-const object -- fine
      test_class_only_const_copy z1(x1);

      // const object -- fine
      test_class_only_const_copy z2(x2);
    }

    {
      test_class_only_non_const_copy x1("xx11", "xx22");
      const test_class_only_non_const_copy y1("yy11", "yy22");

      // fine -- fine
      test_class_only_non_const_copy z(x1);

      // compiler error
      // test_class_only_non_const_copy k(y1);
    }

    {
      cout << "---------------- " << endl;
      test_class_both_copy x1("xx11", "xx22");
      const test_class_both_copy y1("yy11", "yy22");

    
    test_class_both_copy z(x1);
    test_class_both_copy k(y1);

    }

}



int main() {

  
  test_copy_construction();

  return 0;

}

