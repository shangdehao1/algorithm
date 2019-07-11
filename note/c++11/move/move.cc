#include "../../leetcode/common.h"


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
  test_move(test_move&& other) : m_data1(std::move(other.m_data1)), m_data2(std::move(other.m_data2)) {
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
    cout << "move operator..." << endl;
  }

private:
  string m_data1;
  string m_data2;
};

}



void test_move_construction () {
  using namespace dehao_move;

  // copy construction
  {
    test_move temp("shangdehao", "zhaozhuoran");
    test_move xx(temp);
  }

  // copy construction
  {
    test_move temp("shangdehao", "zhaozhuoran");
    test_move xx = temp;
  }

  // move construction
  {
    test_move temp("shangdehao", "zhaozhuoran");
    test_move xx(std::move(temp));
  }

  // move construction
  {
    test_move temp("shangdehao", "zhaozhuoran");
    test_move xx = std::move(temp);
  }

  // assign operator
  {
    test_move temp("shangdehao", "zhaozhuoran");
    test_move xx;
    xx = temp;
  }

  // move construction
  {
    test_move temp("shangdehao", "zhaozhuoran");
    test_move xx;
    xx = std::move(temp);
  }

}



int main() {
  
  test_move_construction();

  return 0;

}

