/*
 * Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
 * 
 * Example:
 * 
 * Input: 5
 * Output:
 * [
 *      [1],
 *     [1,1],
 *    [1,2,1],
 *   [1,3,3,1],
 *  [1,4,6,4,1]
 * ]
 */

vector<vector<int>> generate(int numRows) 
{
  vector<vector<int>> result;

  auto generate_number = [] (const vector<int>& current, vector<int>& result) {
    result.push_back(1);
    for (int i = 1; i < current.size(); i++) {
      result.push_back(current[i - 1] + current[i]);
    }
    result.push_back(1);
  };

  if (numRows-- > 0) {
    result.push_back(vector<int>(1,1));
  }

  while (numRows-- > 0) {
    vector<int> temp;
    generate_number(result.back(), temp);
    result.push_back(temp);
  } 

  return result;
}

