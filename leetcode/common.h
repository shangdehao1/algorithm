#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<bitset>
#include<vector>
#include<assert.h>

#include<functional>

#include <unordered_set>
#include <unordered_map>


#include <numeric>

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
