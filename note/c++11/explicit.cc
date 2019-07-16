#include <iostream>
#include <string>
#include <assert.h>


using namespace std;


class A
{
public:
    A() { 
      a = "default-construction";
    }                

    A(int temp) { 
      a = "one-param-construction";
    }       

    A(const A&  temp) {
      a = "copy-construction";
    } 

    string a;
};

void test_implicit() {

  A temp1(0);  
  assert(temp1.a == "one-param-construction");

  A temp2 = 0;
  assert(temp2.a == "one-param-construction");
  
  A temp3(temp2);
  assert(temp3.a == "copy-construction");

  A temp4 = temp2;
  assert(temp4.a == "copy-construction");

  auto temp_function = [](A temp) {
    assert(temp.a == "one-param-construction");
  };

  temp_function(0);
}

class B 
{
public:
    B() { 
      b = "default-construction";
    }                

    explicit B(int temp) { 
      b = "one-param-construction";
    }       

    explicit B(const B&  temp) {
      b = "copy-construction";
    } 

    string b;
};


void test_explicit() {
  B temp0;

  B temp1(0);
  assert(temp1.b == "one-param-construction");

  // ==> compiler error: conversion from ‘int’ to non-scalar type ‘B’ requested 
  // B temp2 = 0;
  // assert(temp2.b == "one-param-construction");

  B temp3(temp0);
  assert(temp3.b == "copy-construction");

  // ==> compiler error: no matching function for call to ‘B::B(B&)’
  // B temp4 = temp0;
  // assert(temp4.b == "copy-construction");

  auto temp_function = [](B temp) {
  };

  // ==> compiler error : no known conversion for argument 1 from ‘int’ to ‘B’
  // temp_function(0);

  // TODO : how to call explicit function....

}


int main() {

  test_implicit();
  test_explicit();

  return 0;
}
