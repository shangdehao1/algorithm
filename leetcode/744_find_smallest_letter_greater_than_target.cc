/*
 * 744. Find Smallest Letter Greater Than Target
 * 
 * Given a list of sorted characters letters containing only lowercase letters, and given a target letter target, 
 * find the smallest element in the list that is larger than the given target.
 * 
 * Letters also wrap around. For example, if the target is target = 'z' and letters = ['a', 'b'], the answer is 'a'.
 * 
 * Examples:
 * Input:
 * letters = ["c", "f", "j"]
 * target = "a"
 * Output: "c"
 * 
 * Input:
 * letters = ["c", "f", "j"]
 * target = "c"
 * Output: "f"
 * 
 * Input:
 * letters = ["c", "f", "j"]
 * target = "d"
 * Output: "f"
 * 
 * Input:
 * letters = ["c", "f", "j"]
 * target = "g"
 * Output: "j"
 * 
 * Input:
 * letters = ["c", "f", "j"]
 * target = "j"
 * Output: "c"
 * 
 * Input:
 * letters = ["c", "f", "j"]
 * target = "k"
 * Output: "c"
 * Note:
 * letters has a length in range [2, 10000].
 * letters consists of lowercase letters, and contains at least 2 unique letters.
 * target is a lowercase letter.
 * 
 */


char nextGreatestLetter(vector<char>& letters, char target) {
  int left = 0;
  int right = letters.size() - 1;

  while (left < right) {
    int mid = (left + right) >> 1;
  
    if ((mid - 1) < 0 && target < letters[mid]) {
      assert(mid == 0);
      return letters[mid];
    } else if ((mid + 1) == letters.size() && target >= letters.back()) {
      assert((mid + 1) == letters.size());
      return letters.front();
    } else if ((mid - 1) >= 0 && letters[mid-1] <= target && target < letters[mid]) {
      return letters[mid];
    } else if (target < letters[mid]) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  
  return ' '; 
}





