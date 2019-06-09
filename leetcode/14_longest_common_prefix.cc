/*

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.


*/



string longestCommonPrefix(vector<string>& strs) {
  string result;
  int index = 0;

  int min_len = INT_MAX;
  for (int i = 0; i < strs.size(); i++) {
    min_len = min(strs[i].size(), min_len); 
  }

  int index = 0;
  while (index < min_len) {
    int temp = strs[0][index];
    for (int i = 1; i < strs.size(); i++) {
      if (temp != strs[i][index]) {
        return result;
      } 
    } 
    result = result + temp; 
  }
  
  return result;        
}


