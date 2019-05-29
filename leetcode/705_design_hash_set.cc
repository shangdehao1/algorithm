/*
 * Design a HashSet without using any built-in hash table libraries.
 * 
 * To be specific, your design should include these functions:
 * 
 * add(value): insert a value into the HashSet. 
 * contains(value) : Return whether the value exists in the HashSet or not.
 * remove(value): remove a value in the HashSet. If the value does not exist in the HashSet, do nothing.
 * 
 * Example:
 * 
 * MyHashSet hashSet = new MyHashSet();
 * hashSet.add(1);         
 * hashSet.add(2);         
 * hashSet.contains(1);    // returns true
 * hashSet.contains(3);    // returns false (not found)
 * hashSet.add(2);          
 * hashSet.contains(2);    // returns true
 * hashSet.remove(2);          
 * hashSet.contains(2);    // returns false (already removed)
 * 
 * Note:
 * 
 * All values will be in the range of [0, 1000000].
 * The number of operations will be in the range of [1, 10000].
 * Please do not use the built-in HashSet library.
 */

// https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
// https://codeforces.com/blog/entry/10297
// People are not actually implementing any form of hash set, so I use tricks

#include "common.h"


static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

struct HashNode 
{
  int val;
  HashNode *left, *right;
    
  HashNode(int v) : val(v), left(nullptr), right(nullptr) {}
  ~HashNode() {
    if(left  != nullptr) delete left;
    if(right != nullptr) delete right;
  }
};

class MyHashSetTree 
{
private:
    HashNode *root;
public:
    MyHashSetTree() : root(nullptr) {}

    ~MyHashSetTree() {
      if(root != nullptr) 
        delete root; // traverses through destructors
    }

     // ========================
    
    HashNode* insert(int key, HashNode* root) {
      if (root == nullptr) {
        return new HashNode(x);
      }

      if (root->val == key) {
        assert(0);
      } else if (root->val > key) {
        root->left = insert(key, root->left);
      } else if (root->val < key) {
        root->right = insert(key, root->right);
      } 

      return root;
    }
    
    bool insert(int x) {
      if (find(x) != nullptr) {
        return false;
      }
        
      root = insert(x, root);
      return true;
    }

    // =======================
    
    HashNode* find_method_1(int key, HashNode* root) {
      while (root != nullptr) {
        if (root->val > key) {
          root = root->left;
        } else if (root->val < key) {
          root = root->right;
        } else {
          return root;
        }
      }

      return root;
    }

    HashNode* find_method_2(int key, HashNode* root) {
      if(root == nullptr || root->val == key) {
        return root;
      }
      return (root->val > key) ? find_method_2(key, root->left) : find_method_2(key, root->right);
      
    }

    HashNode* find(int key) {
      if(1) {
        return find_method_1(key, root);
      } else {
        return find_method_2(key, root);
      }
    }
    
    // ========================

    HashNode* find_min_method_1(HashNode* root) {
      if(root == nullptr) {
        return nullptr;
      }

      while(root->left != nullptr) {
        root = root->left;
      }
      
      return root;
    }
    
    HashNode* find_min_method_2(HashNode* root) {
      if(root == nullptr) {
        return nullptr;
      }

      return (root->left) == nullptr ? root : find_min_method_2(root->left);
    }

    HashNode* find_min(HashNode* root) {
      if (1) {
        return find_min_method_1(root);
      } else {
        return find_min_method_2(root);
      }
    }

    // ==================

    HashNode *remove_min_method_1(HashNode* root) {
      if (root == nullptr) {
        return nullptr;
      }

      if (root->left != nullptr) {
        root->left = remove_min_method_1(root->left);
        return root;
      }
      
      HashNode* right_node = root->right;
      
      root->left = root->right = nullptr; 
      delete root;

      return right_node;
    }

    // TODO : bug 
    HashNode* remove_min_method_2 (HashNode* root) {
      if (root == nullptr) {
        return nullptr;
      }

      HashNode* parent_node = nullptr;

      while (root->left != nullptr) {
        parent_node = root;
        root = root->left;
      }

      HashNode* right_node = root->right;
      if (parent_node != nullptr) {
        parent_node->left = right_node;
      } 
      
      root->left = root->right = nullptr;
      delete root;

      return right_node;
    }

    HashNode* remove_min(HashNode* root) {
      if(1) {
       return remove_min_method_1(root);
      } else {
       return  remove_min_method_2(root);
      }
    }
    
    HashNode *remove(int x, HashNode *parent) 
    {
        HashNode *current = parent;
        HashNode *left = nullptr;
        HashNode *right = nullptr;
        int currentValue;

        if (current != nullptr) {
          left = current->left;
          right = current->right;
          currentValue = current->val;
        }

        if (current == nullptr) {
            return nullptr;
        } else if (x < currentValue) {
            current->left = remove(x, left);
        } else if (x > currentValue) {
            current->right = remove(x, right);
        } else if (left != nullptr && right != nullptr) {
            current->val = find_min(right)->val;
            current->right = remove_min(right);
        } else {
            current = (left != nullptr) ? left : right;

            parent->right = parent->left = nullptr;
            delete parent;
        }

        return current;
    }
    
    bool remove(int x) {
      if(nullptr == find(x))
        return false;
       
      root = remove(x, root);
      return true;
    }
};

class MyHashSet {
private:
    MyHashSetTree tree;
public:
    MyHashSet() {
    }
    
    void add(int key) {
      tree.insert(key);
    }
    
    void remove(int key) {
      tree.remove(key);
    }
    
    bool contains(int key) {
      return tree.find(key) != nullptr;
    }
};


int main() {
  return 0;

}


