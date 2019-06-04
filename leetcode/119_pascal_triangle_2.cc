/*
Pascal's Triangle II

Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.

In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 3

              1
            1   1
          1   2   1
        1   3   3   1     <------------ 3

Output: [1,3,3,1]
Follow up:

Could you optimize your algorithm to use only O(k) extra space?

*/


vector<int> getRow(int rowIndex) 
{
  if (rowIndex < 0) return vector<int>();
  if (rowIndex < 1) return vector<int>{1};

  vector<int> current({1, 1});; 
  vector<int> next;
  while ((rowIndex--) > 1) {
    next.push_back(1);
    for (int i = 1; i < current.size(); i++) {
      next.push_back(current[i - 1] + current[i]); 
    }
    next.push_back(1);
    swap(current, next);
    next.clear();
  }

  return current;
}


