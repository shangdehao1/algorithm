#include <iostream>
#include <string>
#include <stdio.h>
#include <assert.h>

using namespace std;


string ten_to_sixth(int data)
{
  string result;

  do
  {
    int temp;
    temp = data & 15;
    data >>= 4; 
    data &= 0xffffffff;
    result += (temp <= 9) ? temp + '0' : (temp - 10) + 'a';
  } while (data);

  return result;
}


int convert(int number, uint16_t index ) {
  
}

int main() {

  assert(ten_to_sixth(1) == "1");
  assert(ten_to_sixth(15) == "f");


  return 0;
}







