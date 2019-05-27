/*
  Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.
  
  == Example 1: ==
  
  Input: "Hello"
  Output: "hello"

  == Example 2: ==
  
  Input: "here"
  Output: "here"

  == Example 3: ==
  
  Input: "LOVELY"
  Output: "lovely"

*/


// ====== 

namespace method1 {

std::string toLowerCase(std::string str) {
    int low = 'a';      
    int high = 'z';
    int between = 'Z' - 'z';
    std::string results;
    for(auto temp : str) {
        if(temp <= high && low <= temp) {
            results += temp;
        } else if(temp <= high - between && low - between <= temp) {
            results += (temp - between);
        } else {
            results += temp;
        }
    }
    return results;
}
}

namespace method2 {
  std::string toLowerCase(std:string str) {
    for(auto& temp : str) {
      if(temp <= 'Z' && 'A' <= temp) {
        temp += ('Z' - 'z');
      }
    }
    return str;
  }
}







