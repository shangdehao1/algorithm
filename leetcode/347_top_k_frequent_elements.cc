/*
 * Given a non-empty array of integers, return the k most frequent elements.
 * 
 * Example 1:
 * 
 *      Input: nums = [1,1,1,2,2,3], k = 2
 *      Output: [1,2]
 * 
 * Example 2:
 * 
 *      Input: nums = [1], k = 1
 *      Output: [1]
 * 
 * Note:
 * 
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
 * 
 */

#include <queue>

#include "common.h"


// ============ using heap ======================

namespace heap {

    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int, int> hash_map;

        for (auto num : nums) { 
          hash_map[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> small_heap;

        for (auto kv : hash_map) {
          small_heap.push({kv.second, kv.first});
          while (small_heap.size() > k) small_heap.pop();
        }

        vector<int> result;
        while (!small_heap.empty()) {
          result.push_back(small_heap.top().second);
          small_heap.pop();
        }

        return result;
    }

}


// ============== using selection algorithm ====================

namespace method { 

    void kselection(vector<pair<int, int>>& data, int first, int last, int k)
    {
        if (first >= last) {
          return;
        }

        auto target = data[first];
        int left = first;
        int right = last;

        while (left < right) {
          while(left < right && data[right].second <= target.second) right--;
          if (left < right) {
            data[left] = data[right];
            left++;
          }

          while (left < right && data[left].second >= target.second) left++;
          if (left < right) {
            data[right] = data[left];
            right--;
          }
        }
        data[left] = target;

        int num = left - first + 1;
        if (num == k) {
          return;
        } else if (num < k) {
            kselection(data, left + 1, last, k - num);
        } else {
            kselection(data, first, left - 1, k);
        }
    }

    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        if (!nums.size()) {
          return {};
        }

        vector<int> result;
        unordered_map<int, int> hash_map;
        for (auto num : nums) { 
          hash_map[num]++;
        }

        vector<pair<int, int>> num_with_cnt;
        for (auto kv : hash_map) {
          num_with_cnt.push_back({kv.first, kv.second});
        }

        kselection(num_with_cnt, 0, num_with_cnt.size() - 1, k);

        for (int i = 0; i < k && i < num_with_cnt.size(); ++i) {
          result.push_back(num_with_cnt[i].first);
        }

        return result;
    }
}


namespace bucket_sort_method {

    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        if (nums.empty()) {
          return {};
        }

        vector<int> result;

        unordered_map<int, int> hash_map;
        for (auto num : nums) {
          hash_map[num]++;
        }

        vector<vector<int>> bucket(nums.size() + 1);
        for (auto kv : hash_map) {
          bucket[kv.second].push_back(kv.first);
        }

        for (int bucket_index = bucket.size() - 1; bucket_index >= 0; bucket_index--) {
          for (int water_index = 0; water_index < bucket[bucket_index].size(); water_index++) {
            result.push_back(bucket[bucket_index][water_index]);
              if (result.size() == k) return result;
          }
        }

        return result;
    }

}



int main () {

  {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> big_queue;

    big_queue.push({1,2});
    big_queue.push({1,3});
    big_queue.push({1,4});
    big_queue.push({2,2});
    big_queue.push({2,2});
    big_queue.push({3,2});
    big_queue.push({4,2});
    big_queue.push({5,2});
    big_queue.push({5,2});

    while (!big_queue.empty()) {
      auto temp = big_queue.top();
      big_queue.pop();
      cout << temp.first << " " << temp.second << endl;
    }
  }

  return 0;

}






