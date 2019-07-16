/*
 *  == Climbing Stairs ==
 * 
 * You are climbing a stair case. It takes n steps to reach to the top.
 * 
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 * 
 * Note: Given n will be a positive integer.
 * 
 * == Example 1: ==
 * 
 * Input: 2
 * 
 * Output: 2
 * 
 * Explanation: There are two ways to climb to the top.
 *   - 1. 1 step + 1 step
 *   - 2. 2 steps
 * 
 * == Example 2: ==
 * 
 * Input: 3
 * 
 * Output: 3
 * 
 * Explanation: There are three ways to climb to the top.
 * 
 *   - 1. 1 step + 1 step + 1 step
 *   - 2. 1 step + 2 steps
 *   - 3. 2 steps + 1 step
 * 
 */


// depth search + cut tree

namespace depth_search_method {

int depth_search(int n, unordered_map<int, int>& hash_map) {
  if (n < 0) return 0;
  if (n == 0) return 1;

  if (hash_map.find(n) != hash_map.end()) {
    return hash_map[n];
  }

  int ret1 = depth_search(n - 1, hash_map);
  int ret2 = depth_search(n - 2, hash_map);

  hash_map[n] = ret1 + ret2;
  hash_map[n - 1] = ret1;
  hash_map[n - 2] = ret2;

  return ret1 + ret2;
}

int climbStairs(int n) 
{
  unordered_map<int, int> hash_map;
  return depth_search(n, hash_map);
}

}


namespace dp_method {

  int climbStairs(int n) 
  {
    if (n < 2) return n;

    vector<int> hash_map(n + 1, 0);
  
    hash_map[1] = 1; 
    hash_map[2] = 2;

    for (int i = 3; i <= n; i++) {
      hash_map[i] = hash_map[i - 1] + hash_map[i - 2];
    }

    return hash_map[n];
  }

}




// too slow
int climbStairs(int n) {
  if (n == 0) return 0;
  if (n == 1) return 1;
  if (n == 2) return 2;

  return climbStairs(n - 1) + climbStairs(n - 2);
}




