#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

namespace method1 {
int get_first_digit(uint32_t data) {
  if (data < 10) {
    return data;
  }

  return get_first_digit(data / 10);
}
}

int main() {

  assert(1 == get_first_digit(1));
  assert(2 == get_first_digit(21));
  assert(2 == get_first_digit(20021));
  assert(3 == get_first_digit(31231231));

  return 0;
}




