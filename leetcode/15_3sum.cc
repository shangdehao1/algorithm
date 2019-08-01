/*
 * Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 *   [-1, 0, 1],
 *   [-1, -1, 2]
 * ]
 * 
 */

vector<vector<int> > threeSum(vector<int> &num) 
{
    vector<vector<int>> result;

    std::sort(num.begin(), num.end());

    for (int i = 0; i < num.size(); i++) {
        
        int target = -num[i];
        int left = i + 1;
        int right = num.size() - 1;

        while (left < right) 
        {
            int sum = num[left] + num[right];
            
            if (sum < target) {
                left = left + 1;
            } else if (sum > target) {
                right = right - 1;
            } else {
                vector<int> temp{num[i], num[left], num[right]};
                result.push_back(temp);
                
                while (left < right && num[left] == temp[1]) left++;

                while (left < right && num[right] == temp[2]) right--;
            }
            
        }

        while (i + 1 < num.size() && num[i + 1] == num[i]) i++;
    }
    
    return result;
}





