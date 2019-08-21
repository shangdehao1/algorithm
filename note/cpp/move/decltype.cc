#include <iostream>
#include <type_traits>
#include <assert.h>
#include <utility>

using namespace std;

void test_base_type() {

  int m_int;
  int& m_lint = m_int;
  int&& m_rint = 1;

  assert((std::is_same<int, decltype(m_int)>::value) == true);
  assert((std::is_same<int&, decltype(m_lint)>::value) == true);
  assert((std::is_same<int&&, decltype(m_rint)>::value) == true);
  
  const int kk = 1;
  assert((std::is_same<const int, decltype(kk)>::value) == true);
}

void test_move() {
  int m_int = 0;

  assert((std::is_same<int, decltype(m_int)>::value) == true);
  assert((std::is_same<int&&, decltype(std::move(m_int))>::value) == true);
}

void test_forward() {
  int m_int = 0;
  int& m_left = m_int;
  int&& m_right = 1;
  
  assert((std::is_same<int&, decltype(std::forward<int&>(m_left))>::value) == true);
  assert((std::is_same<int&&, decltype(std::forward<int&&>(m_right))>::value) == true);
}


int main() {

  test_base_type();
  test_move();
  test_forward();

  return 0;
}
