/*
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:

Input: "hello"
Output: "holle"
Example 2:

Input: "leetcode"
Output: "leotcede"

*/

string reverseVowels(string s) {

  unordered_set<char> hash_map{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};   

  vector<int> index;

  for (int i = 0; i < s.size(); i++) {
    if (hash_map.find(s[i]) != hash_map.end()) {
      index.push_back(i);
    }    
  }

  int left = 0;
  int right = index.size() - 1;

  while (left < right) {
    swap(s[index[left++]], s[index[right--]]);
  }
  
  return s;
}

