#include "common.h"



int main() {
  
  assert(sizeof(uint32_t) == 4);
  assert(sizeof(uint16_t) == 2);
  assert(sizeof(uint64_t) == 8);


//  assert(sizeof(0x1) == 2);

  cout <<  sizeof(0x01) << endl;

  return 0;
}
