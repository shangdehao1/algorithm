/*
 * Move as rvalue
 * Returns an rvalue reference to arg.
 * 
 * This is a helper function to force move semantics on values, even if they have a name: Directly using the returned value causes arg to be considered an rvalue.
 * 
 * Generally, rvalues are values whose address cannot be obtained by dereferencing them, either because they are literals or because they are temporary in nature (such as values returned by functions or explicit constructor calls). By passing an object to this function, an rvalue that refers to it is obtained.
 * 
 * Many components of the standard library implement move semantics, allowing to transfer ownership of the assets and properties of an object directly without having to copy them when the argument is an rvalue.
 * 
 * Although note that -in the standard library- moving implies that the moved-from object is left in a valid but unspecified state. Which means that, after such an operation, the value of the moved-from object should only be destroyed or assigned a new value; accessing it otherwise yields an unspecified value.
 * 
 * The function returns the same as:
 *  
 * static_cast<remove_reference<decltype(arg)>::type&&>(arg)
 * 
 * Header <algorithm> overloads this function, providing a similar behavior applied to ranges.
 * 
 */
#include <iostream>
#include <vector>
#include <string>
#include <assert.h>

using namespace std;


namespace dehao_move {

class test_move {
public:
  test_move() {
    x = "default-construction";
  }

  test_move(string x1, string x2) : m_data1(x1), m_data2(x2) {
    x = "two-param-construction";
  }

  ~test_move() {}

  test_move(const test_move& other) {
    m_data1 = other.m_data1;
    m_data2 = other.m_data2;
    x = "copy-construction";
  }

  test_move(test_move&& other) : m_data1(std::move(other.m_data1)), m_data2(std::move(other.m_data2)) {
    assert(other.m_data1.size() == 0);
    assert(other.m_data2.size() == 0);
    x = "move-construction";
  }

  test_move& operator=(const test_move& other) {
    m_data1 = other.m_data1;
    m_data2 = other.m_data2;
    x = "assign-operator";
  }

  test_move& operator=(test_move&& other) {
    m_data1 = std::move(other.m_data1);
    m_data2 = std::move(other.m_data2);
    assert(other.m_data1.size() == 0);
    assert(other.m_data2.size() == 0);
    x = "move-operator";
  }

  string m_data1;
  string m_data2;
  string x;
};

}



void test_move_construction () {
  using namespace dehao_move;

  {
    test_move temp("shangdehao", "zhaozhuoran");
    test_move xx(temp);

    assert(xx.x == "copy-construction");
  }

  {
    test_move temp("shangdehao", "zhaozhuoran");
    test_move xx = temp;

    assert(xx.x == "copy-construction");
  }

  {
    test_move temp("shangdehao", "zhaozhuoran");
    test_move xx(std::move(temp));

    assert(xx.x == "move-construction");
  }

  {
    test_move yy("x", "y");
    test_move xx(std::move(yy));

    assert(xx.x == "move-construction");
  }

  {
    test_move temp("shangdehao", "zhaozhuoran");
    test_move xx = std::move(temp);

    assert(xx.x == "move-construction");
  }

  // assign operator
  {
    test_move temp("shangdehao", "zhaozhuoran");
    test_move xx;
    xx = temp;
    assert(xx.x == "assign-operator");
  }

  // move operator
  {
    test_move temp("shangdehao", "zhaozhuoran");
    test_move xx;
    xx = std::move(temp);
    assert(xx.x == "move-operator");
  }

}



int main() {
  
  test_move_construction();

  return 0;

}

