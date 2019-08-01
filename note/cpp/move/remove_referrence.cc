/*
 * remove reference
 * 
 * Obtains the non-reference type to which T refers.
 * 
 * The transformed type is aliased as member type remove_reference::type.
 * 
 * If T is a reference type (either lvalue reference or rvalue reference), this is the type to which it refers. Otherwise, it is the same as T, unchanged.
 * 
 * Notice that this class merely obtains a type using another type as model, but it does not transform values or objects between those types.
 */

#include <iostream>
#include <type_traits>
#include <assert.h>

int main() 
{
  typedef int&& rval_int;
  typedef std::remove_reference<int>::type A;
  typedef std::remove_reference<int&>::type B;
  typedef std::remove_reference<int&&>::type C;
  typedef std::remove_reference<rval_int>::type D;


  std::cout << std::boolalpha;

  assert((std::is_same<int, A>::value) == true);
  assert((std::is_same<int, B>::value) == true);
  assert((std::is_same<int, C>::value) == true);
  assert((std::is_same<int, D>::value) == true);

  return 0;
}
