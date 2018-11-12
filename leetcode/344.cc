/*
 *  Write a function that takes a string as input and returns the string reversed.
 *  
 *  Example 1:
 *  
 *  Input: "hello"
 *  Output: "olleh"
 *  Example 2:
 *  
 *  Input: "A man, a plan, a canal: Panama"
 *  Output: "amanaP :lanac a ,nalp a ,nam A"
 *  
 */



string reverseString(string s) {
  reverse(s.begin(), s.end());
  return s;
}


string reverseString(string s) {
  int index;
  if(s.size()%2 == 0) {
    index = s.size()%2;
  } else {
    index = s.size()%2 + 1;
  }
  for (int i = 0; i < index; i++) {
    swap(s[i], s[s.size() - i]);
  }
  return s;
}





