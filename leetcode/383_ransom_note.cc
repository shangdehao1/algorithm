/*
 * Given an arbitrary ransom note string and another string containing letters from all the magazines, 
 * write a function that will return true if the ransom note can be constructed from the magazines ; 
 * otherwise, it will return false.
 * 
 * Each letter in the magazine string can only be used once in your ransom note.
 * 
 * Note:
 * You may assume that both strings contain only lowercase letters.
 * 
 * canConstruct("a", "b") -> false
 * canConstruct("aa", "ab") -> false
 * canConstruct("aa", "aab") -> true
 * 
 */

#include "common.h"

// mistake specification.....:(

namespace method0 { 

bool canConstruct(string ransomNote, string magazine) {
  
  int index_target = 0;
  int index_array = 0;

  while (index_target < ransomNote.size()) {
     
    while (index_array < magazine.size()) {
      if (ransomNote[index_target] == magazine[index_array]) { 
        index_target++;
        index_array++;
        break;
      }
      index_array++;
    }

    if (index_array == magazine.size()) {
      break;
    }
  }

  return index_target == ransomNote.size();
}


}




// =====  unordered_map method ======

namespace method1 {
bool canConstruct(string ransomNote, string magazine) {
  unordered_map<int, int> map; 
  for (auto t : magazine) {
    map[t]++;
  }

  for (auto t : ransomNote) {
    map[t]--;
    if (map[t] < 0) return false;
  }
  return true;
}
}

namespace method2 {

bool canConstruct(string ransomNote, string magazine) {
  vector<int> hash_map(26, 0); 
 
  for (auto t : magazine) {
    hash_map[t - 'a']++;
  }

  for (auto t : ransomNote) {
    if(--hash_map[t - 'a'] < 0) {
      return false;
    }
  }
  return true;
}

}




int main() {

  
  unordered_map<string, int> map;
  map["sdh"]++;
  map["sdh"]++;
  map["zzr"]++;
  map["zzr"]++;
  cout << map["sdh"] << endl;
  cout << map["zzr"] << endl;

  
  return 0;



}
