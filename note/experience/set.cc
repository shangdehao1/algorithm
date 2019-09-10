

#include <iostream>
#include <set>

using namespace std;


int main() {


  set<int> temp;

  temp.insert(1);
  temp.insert(2);
  temp.insert(3);
  temp.insert(4);

  for(auto i : temp)  {
    cout << i << endl;
  }

}
