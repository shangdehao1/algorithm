#include <iostream>
#include <assert.h>

using namespace std;



// Pointers: A pointer is a variable that holds memory address of another variable. A pointer needs to be dereferenced with * operator to access the memory location it points to.

// References : A reference variable is an alias, that is, another name for an already existing variable. A reference, like a pointer is also implemented by storing the address of an object.


/*
  == differences ===

   - 1 : initalisation

   - 2 : re-assignment

   - 3 : memory address
         a reference shares the same memory address with the original variable

   - 4 : nullptr

   - 5 : Various arithmetic operations can be performed on pointers whereas there is no such thing called Reference Arithmetic.
        (but you can take the address of an object pointed by a reference and do pointer arithmetics on it as in &obj + 5).)



The performances are exactly the same, as references are implemented internally as pointers. But still you can keep some points in your mind to decide when to use what :

 - Use references
   In function parameters and return types.

 - Use pointers:
    - arithmetic 
      Use pointers if  pointer arithmetic or passing NULL-pointer is needed. For example for arrays (Note that array access is implemented using pointer arithmetic).

    - nullptr and assignment
      To implement data structures like linked list, tree, etc and their algorithms because to point different cell,we have to use the concept of pointers.

*/


void test_memory_address() {
  int i = 0;
  int* p = &i;
  int& r = i;
  
  assert(&r == &i); // reference share the same memory address with the original variable.

  assert(p == &i); // 

  assert((void*)&p != (void*)&i); // force to comparation. 
}


void test_nullptr() {
  int* p = nullptr;

  // compiler error : invalid initialization of non-const reference of type ‘int&’ from an rvalue of type ‘std::nullptr_t’
  // int& r = nullptr;
}


int main() {


  test_memory_address();

  return 0;
}
