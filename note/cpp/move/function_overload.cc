#include <iostream>
#include <assert.h>
#include <string>

using namespace std;

namespace _test_function_overload {
  // 1
  void output_information(string m) {
  }

  // 2
  void output_information(string&& m) {
  }

  // 3
  void output_information(string& m) {
  }
}


void test_function_overload() {

  using namespace _test_function_overload;

  // compiler error : 1 and 3 is ambiguous
  {
    string m;
    // output_information(m);
  }

  // compiler error : 1 and 2 is ambiguous
  {
    // output_information("1111");
  }

  // compiler error : 1 and 2 is ambiguous
  {
    string m;
    // output_information(std::move(m));
  }
}


int main() {

  test_function_overload();

  return 0;
}
