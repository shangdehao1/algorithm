/*
Isomorphic Strings

Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true

Note:
You may assume both s and t have the same length.

*/


namespace encoding_mehod_using_hash_map {

bool isIsomorphic(string s, string t) {

  auto encoding = [](string s)
  {
    unordered_map<char, int> hash_map;
    int index = 0;
    string result;

    for (auto t : s) {
      if (hash_map.find(t) == hash_map.end()) {
        hash_map[t] = index++ + '0';
      }
      result += hash_map[t];
    }
    return result;
  };

  return encoding(s) == encoding(t);
}

}


namespace encoding_method_based_on_256_char {


bool isIsomorphic(string s, string t) {

  vector<int> hash_map_s(256, 0);
  vector<int> hash_map_t(256, 0);

  for (int i = 0; i < s.size(); i++) {
    if (hash_map_s[s[i]] != hash_map_t[t[i]]) return false;

    hash_map_s[s[i]] = hash_map_t[t[i]] = i + 1;
  }
  return true;
}


}






