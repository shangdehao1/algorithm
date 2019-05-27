/*
You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  

Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. 

Letters are case sensitive, so "a" is considered a different type of stone from "A".

Example 1:

Input: J = "aA", S = "aAAbbbb"
Output: 3
Example 2:

Input: J = "z", S = "ZZ"
Output: 0
Note:

S and J will consist of letters and have length at most 50.
The characters in J are distinct.

*/


namespace method1 {

int numJewelsInStones(string J, string S) {
  uint64_t index = 0;
  for(auto temp : S) {
    if(J.find(temp) != string::npos) {
      index++;
    }
  }
  return index;
}

}

namespace method2 {

  int numJewelsInStones(string J, string S) {
    int result = 0;
    unordered_set<char> map(J.begin(), J.end());
    for (auto temp : S) {
      if(map.find(temp) != map.end()) {
        result++;
      }
    }
    return result;
  }

}



int main() {
  Solution xx;
  xx.numJewelsInStones("aaaAAAA", "ccc");

}
