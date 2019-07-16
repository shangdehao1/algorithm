/*

Given a binary matrix A, we want to flip the image horizontally, then invert it, and return the resulting image.

To flip an image horizontally means that each row of the image is reversed.  For example, flipping [1, 1, 0] horizontally results in [0, 1, 1].

To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0. For example, inverting [0, 1, 1] results in [1, 0, 0].

Example 1:

Input: [[1,1,0],
	[1,0,1],
	[0,0,0]]

Output: [[1,0,0],
	 [0,1,0],
	 [1,1,1]]

Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]

Example 2:

Input: [[1,1,0,0],
        [1,0,0,1],
   	[0,1,1,1],
	[1,0,1,0]]

Output: [[1,1,0,0],
	 [0,1,1,0],
	 [0,0,0,1],
	 [1,0,1,0]]

Explanation: First reverse each row: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]].

Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]

Notes:

1 <= A.length = A[0].length <= 20
0 <= A[i][j] <= 1

*/

#include <iostream> 
#include <vector> 
#include <algorithm> 

using namespace std;

// TODO better method ???

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
      // if want to modify element, use refference symbol.
      for(auto& row_vec : A) {
        reverse(row_vec.begin(), row_vec.end());
        for(auto &temp : row_vec) {
          if(temp == 0) {
            temp = 1;
          } else {
            temp = 0;
          }
        }
      }
      return A;  
    }
};



int main() {

 
  vector<int> a{1,2,3,4,5,6,7,8,9,0};

  // ## stl algorithm
  reverse(a.begin(), a.end()); 
  

  for(auto temp : a) {
    cout<<temp<<" ";
  }

  cout<<endl;

  // swap
  // 4 --> 4/2 = 2 --> "< 2"
  // 5 --> 5/2 = 2 --> "< 2"
  for(int i = 0; i < a.size()/2; i++) {
    int temp = a[i];
    a[i] = a[a.size() - 1 - i];
    a[a.size() -1 - i] = temp;
  }

  for(auto temp : a) {
    cout<<temp<<" ";
  }









  return 0;
}









