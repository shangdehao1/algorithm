#include <iostream>
#include <memory>

using namespace std;

class context {
public:
  int complete(int r) {
    delete this;
    return 0;
  }

  context() {}
  ~context() {}
};


int main() {

  while(1) {
    {
      unique_ptr<context> temp(new context());
      temp->complete(1);
    }
  }

  return 0;
}

