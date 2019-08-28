#include "common.h"




int main() {

  for (int i = 0; i < 64; i++) {
    cout << bitset<64>(1ull<<i) << "  ====>>>> "<< (1ull << i) << endl;
  }


  return 0;
}

