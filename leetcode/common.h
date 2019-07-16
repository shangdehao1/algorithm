#ifndef LEETCODE_COMMON_H
#define LEETCODE_COMMON_H

#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<bitset>
#include<vector>
#include<assert.h>

#include <set>
#include<stack>
#include <queue>
#include<functional>

#include <unordered_set>
#include <unordered_map>

#include <numeric>

#include <sstream>

#include <list>


using namespace std;


struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


 struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
 };



template<typename T> 
void output_container(T& data, string information = "") {
  std::cout << information << std::endl;

  for(auto t : data) {
    std::cout << t << " ";
  }

  std::cout << endl;
}

#endif
