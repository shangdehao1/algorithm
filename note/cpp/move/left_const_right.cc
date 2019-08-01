#include <iostream>
#include <stdio.h>
#include <string>
#include <assert.h>

using namespace std;


/*
 *   ------------------------------------------------------------------------
 *   |                   |            function version                      |
 *   | actual parameter  ----------------------------------------------------
 *   |                   |     left value   |  const value |  right value   |
 *   ------------------------------------------------------------------------
 *   |  left value       |    1st choice    |   2nd choice |  no-compatible | 
 *   ------------------------------------------------------------------------
 *   |  const value      |   no-compatible  |  1st choice  |  no-compatible | 
 *   ------------------------------------------------------------------------
 *   |  right value      |   no-compatible  |  2nd choice  |  1st choice    |
 *   ------------------------------------------------------------------------
 */

namespace _test_left_1 {

string print(std::string& name) {
  return "left-value";
}

string print(const std::string& name) {
  return "const-value";
}

string print(std::string&& name) {
  return "right-value";
}

}

void test_left_1() {
  using namespace _test_left_1;

  string left_value("shangdehao");

  assert(print(left_value) == "left-value");
}

// ========================

namespace _test_left_2 {

string print(const std::string& name) {
  return "const-value";
}

string print(std::string&& name) {
  return "right-value";
}

}

void test_left_2 () {
  using namespace _test_left_2;
  string left_value("x");

  assert(print(left_value) == "const-value");
}

// ========================

namespace _test_left_3 {

string print(std::string&& name) {
  return "right-value";
}

}

void test_left_3() {
  using namespace _test_left_3;

  string left_value("s");

  // can't pass compiler
  // assert(print(left_value) == "right-value");
}

// ========================

namespace _test_const_1 {

string print(std::string& name) {
  return "left-value";
}

string print(const std::string& name) {
  return "const-value";
}

string print(std::string&& name) {
  return "right-value";
}

}

void test_const_1() {
  using namespace _test_const_1;

  const string const_value("s");

  assert(print(const_value) == "const-value");
}

// =========================

namespace _test_const_2_3 {

string print(std::string& name) {
  return "left-value";
}

string print(std::string&& name) {
  return "right-value";
}

}

void test_const_2_3() {
  using namespace _test_const_2_3;
  
  const string const_value("s");

  // can't pass compiler...
  // assert(print(const_value) == "const-value");
  
}

// =========================

namespace _test_right_1 {

string print(std::string& name) {
  return "left-value";
}

string print(const std::string& name) {
  return "const-value";
}

string print(std::string&& name) {
  return "right-value";
}

}

void test_right_1 () {
  using namespace _test_right_1;

  assert(print("123") == "right-value");
}

// =========================

namespace _test_right_2 {

string print(std::string& name) {
  return "left-value";
}

string print(const std::string& name) {
  return "const-value";
}

}

void test_right_2() {
  using namespace _test_right_2;

  assert(print("123") == "const-value");
}

// =========================

namespace _test_right_3 {

string print(std::string& name) {
  return "left-value";
}

}

void test_right_3() {
  using namespace _test_right_3;

  // assert(print("123") == "left-value");
}

// =========================

int main() {

  test_left_1();
  test_left_2();
  test_left_3();

  test_const_1();
  test_const_2_3();

  test_right_1();  
  test_right_2();
  test_right_3();

  return 0;
}

