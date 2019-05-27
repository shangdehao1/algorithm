/*
 *
 * Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
 * 
 * Example 1:
 * 
 * Input:  "Let's take LeetCode contest"
 * Output: "s'teL ekat edoCteeL tsetnoc"
 *
 * Note: In the string, each word is separated by single space and there will not be any extra space in the string.
 * 
 */

// method 1 : split + reverse

namespace method1 {

string reverseWords(string s) 
{
  auto explode = [](const string& s, const char& c) {
    string buff{""};
    vector<string> results;

    for(auto n : s) {
      if(n != c) {
        buff += n;
      } else {
        if (n == c && buff != "") {
          results.push_back(buff);
          buff = "";
        }
      }
    }

    if(buff != "") {
      results.push_back(buff);
    }
    return results;
  }
          
  vector<string> temp(explode(s, ' ')); 
  
  string results;
  for(auto xx : temp) {
    reverse(xx.begin(), xx.end());
    results += (xx + " ");
  } 
  results.pop_back();

  return results;
}

}


// method 3 : iterator + reverse

namespace method3 
{
  string reverseWords(string s) 
  {
    int left = 0;   
    int right = 0;

    while(left <= right && left < s.size()) {
      while(right < s.size() && s[right] != ' ') {
        right++;
      }

      if((left < right && (s[right] == ' '|| right == s.size()))) {
        reverse(s.begin() + left, s.begin() + right); 
      }
      
      left = ++right;
    }
    return s;
  }

}




