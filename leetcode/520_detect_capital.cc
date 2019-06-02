/*
  Given a word, you need to judge whether the usage of capitals in it is right or not.
  
  We define the usage of capitals in a word to be right when one of the following cases holds:
  
  - All letters in this word are capitals, like "USA".

  - All letters in this word are not capitals, like "leetcode".

  - Only the first letter in this word is capital if it has more than one letter, like "Google".
    Otherwise, we define that this word doesn't use capitals in a right way.

  Example 1:

  - Input: "USA"
  - Output: True

  Example 2:

  - Input: "FlaG"
  - Output: False

  Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.
  
*/

#include "common.h"


 bool detectCapitalUse(string word)  {
   if(word.size() == 1) {
    return true; 
   }

  bool first_small = ('A' <= word[0] && word[0] <= 'Z') ? false : true;
     
  for(int i = 1; i < word.size(); i++) {
     if(first_small == true && 'A' <= word[i] && word[i] <= 'Z') {
         return false;
     } 
  }
  
  bool second_small = true;
  for(int i = 1; i < word.size(); i++) {
      
      if(first_small == false && i == 1 && 'A' <= word[i] && word[i] <= 'Z') {
          second_small = false;
          continue;
      }
      
      if(second_small == true && 'A' <= word[i] && word[i] <= 'Z'){
          return false;
      }
      if(second_small == false && 'a' <= word[i] && word[i] <= 'z') {
          return false;
      }
  }
     
  return true;

}

