/*
 *
 *  Given a string S and a character C, return an array of integers representing the shortest distance from the character C in the string.
 * 
 *  Example 1:
 *  
 *  Input: S = "loveleetcode", C = 'e'
 *  Output: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
 *   
 *  
 *  Note:
 *  
 *  S string length is in [1, 10000].
 *  C is a single character, and guaranteed to be in string S.
 *  All letters in S and C are lowercase.
 * 
 */

// d-p method
//

namespace method1 {

vector<int> shortestToChar(string S, char C) {
    int n = S.size();
    vector<int> results(S.size(), S.size());

    int index = -n;
    for(int i = 0; i < S.size(); i++) {
        if(S[i] == C) {
            index = i;
        } 
       results[i] = min(results[i], abs(i - index));
    }

    for(int i = S.size() -1; i >= 0 ; i--) {
        if(S[i] == C) {
            index = i;
        }
        results[i] = min(results[i], abs(i - index));
    }

    return results;

}

}

namespace method2 {

  vector<int> shortestToChar(string S, char C) {
    vector<int> result(S.size(), S.size());

    int index = -S.size();

    for (int i = 0; i < S.size(); i++) {
      if(S[i] == C) index = i;
      result[i] = min(result[i], abs(i - index));
    }

    index = -S.size();

    for (int i = S.size() - 1; i >= 0; i--) {
      if(S[i] == C) index = i;
      result[i] = min(result[i], abs(i - index));
    }
  }

  return result;
}


