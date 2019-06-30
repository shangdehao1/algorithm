/*
 * Range Sum Query - Immutable
 * 
 * Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
 * 
 * Example:
 * Given nums = [-2, 0, 3, -5, 2, -1]
 * 
 * sumRange(0, 2) -> 1
 * sumRange(2, 5) -> -1
 * sumRange(0, 5) -> -3
 * 
 * Note:
 * You may assume that the array does not change.
 * There are many calls to sumRange function.
 * 
 */

// TODO : better method....

namespace general_method {

class NumArray {
public:
    NumArray(vector<int>& nums) : m_nums(nums) {
      long long index = 0;
      for (int i = 0; i < nums.size(); i++) {
        index += nums[i]; 
        m_data.push_back(index);
      }
    }
    
    int sumRange(int i, int j) {
      return m_data[j] - m_data[i] + m_nums[i];
        
    }
private : 
  vector<long long> m_data;
  const vector<int> m_nums;
};

}




namespace optimization_general_method {

class NumArray {
public:
    NumArray(vector<int>& nums) {
      m_data.push_back(0);
      long long index = 0;
      for (auto temp : nums) {
        index += temp;
        m_data.push_back(index);
      }
       
        
    }
    
    int sumRange(int i, int j) {
      return m_data[j + 1] - m_data[i];
    }

private : 
  vector<long long> m_data;

};

}



int main() {return 0; }







