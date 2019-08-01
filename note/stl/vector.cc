#include <iostream>
#include <vector>
#include <assert.h>


using namespace std;

namespace testing_emplace_back {

  class Test {
  public:
    Test(int i, int j, int k) {
      cout << "general construction...." << endl;
      index++;
    }
  
    Test(const Test& other) {
      cout << "copy construction...." << endl;
      index++;
    }
  
    static int index;
  };
  
  int Test::index = 0;
}

void test_emplace_back() {
  using namespace testing_emplace_back;

  // stupid method. 
  {
    Test::index = 0;

    vector<Test> result;

    Test test(1, 2, 3); 
    assert(Test::index == 1);

    result.push_back(test);
    assert(Test::index == 2);
  }

  {
    Test::index = 0;
    vector<Test> result;

    result.emplace_back(1, 2, 3);
    assert(Test::index == 1);
  }


  {
    Test::index = 0;

    vector<Test> result;
  }
  

}








int main() {

  vector<int> data[3];

  cout << data[0].size() << endl;
  cout << data[1].size() << endl;
  cout << data[2].size() << endl;



  test_emplace_back();


  return 0;
}


