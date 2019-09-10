#include "common.h"
#include <vector>

using namespace std;

int main() {

  char buf[100];
  int x = 1; 
  snprintf(buf, sizeof(buf), "key123456%011d", x);

  assert(sizeof(buf) == 100);

  string temp(buf);
  assert(temp.size() == 20);

  

  return 0;
}
