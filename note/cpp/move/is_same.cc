/*
 * template <class T, class U> 
 * struct is_same;
 *
 * Trait class that identifies whether T is the same type as U, 
 * including having the same const and/or volatile qualification, if any.
 * 
 * Two different type names are considered to represent the same type 
 * if-and only-if one is a typedef of the other: 
 *
 * Two names representing types with the exact same characteristics 
 * but which none is a typedef of the other are not considered the same type.
 * 
 * is_same inherits from integral_constant as being either true_type or false_type, depending on whether T and U are the same type.
 */

#include <iostream>
#include <type_traits>
#include <cstdint>
#include <assert.h>

using namespace std;

typedef int integer_type;
struct A { int x,y; };
struct B { int x,y; };
typedef A C;


void test_const () {
  assert((std::is_same<int, const int>::value) == false);
  assert((std::is_same<const int, const int>::value) == true);
}

void test_volatile() {
  assert((std::is_same<int, volatile int>::value) == false);
  assert((std::is_same<volatile int, volatile int>::value) == true);
}

void test_struct () {
  assert((std::is_same<A, B>::value) == false);
  assert((std::is_same<A, C>::value) == true);
}

void test_typedef() {
  assert((std::is_same<integer_type, int>::value) == true);
}

int main() {
  std::cout << std::boolalpha;
  
  test_const();
  test_volatile();
  test_struct();
  test_typedef();

  return 0;
}
