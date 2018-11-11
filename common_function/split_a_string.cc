#include <iostream> 
#include <vector>
#include <string>

using namespace std;


const vector<string> explode(const string& s, const char& c) {
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


int main()
{
    string str{"the quick brown fox jumps over the lazy dog"};
    vector<string> v{explode(str, ' ')};
    for(auto n:v) cout << n << endl;
    
    return 0;
}



