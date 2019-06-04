/*
 * Two Sum
 * 
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * 
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * 
 * Example:
 * 
 * Given nums = [2, 7, 11, 15], target = 9,
 * 
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 * 
 */


// this solution is very rough........

namespace general_method {

vector<int> twoSum(vector<int>& nums, int target) {

  unordered_map<int, vector<int>> hash_map;
  for (int i = 0; i < nums.size(); i++) {
    hash_map[nums[i]].push_back(i); 
  }

  sort(nums.begin(), nums.end());

  int left = 0; 
  int right = nums.size() - 1;

  while (left <= right) {
    int index = nums[left] + nums[right];
    if (index == target) {
      int temp1 = hash_map[nums[left]].back();
      hash_map[nums[left]].pop_back();
      int temp2 = hash_map[nums[right]].back();
      return vector<int>{temp1 , temp2};
    } else if (index < target) {
      left++;
    } else {
      right--;
    }
  }

  return vector<int>{};
}

} //namespace 


namespace _method {

vector<int> twoSum(vector<int> &numbers, int target)
{
  unordered_map<int, int> hash;
  vector<int> result;

  for (int i = 0; i < numbers.size(); i++) 
  {
    int gap = target - numbers[i];

    if (hash.find(gap) != hash.end()) {
      result.push_back(hash[gap] + 1);
      result.push_back(i + 1);                  
      return result;
    }
    hash[numbers[i]] = i;
  }
  return result;
}

}

// =========== nice solution ==============

namespace nice_solution {

vector<int> twoSum(vector<int> &nums, int target) {

  unordered_map<int, int> hash_map;
  
  for (int i = 0; i < nums.size(); i++) {
    int gap = target - nums[i];
    if (hash_map.find(gap) != hash_map.end()) {
      return vector<int>{i, hash_map[gap]};
    }
    hash_map[nums[i]] = i;
  }
  return vector<int>{};
}

}
