#include <iostream>
#include <stdio.h>

using namespace std;



int main(int argc, char** argv) {

  if (argc == 1) {
    printf("please enter more parameter to verify this test function...\n");
    return 0;
  }

  for (int i = 0; i < argc; i++) {
    printf("paramter list : argv[%d] = %s\n", i, argv[i]);
  }

  return 0;
}
