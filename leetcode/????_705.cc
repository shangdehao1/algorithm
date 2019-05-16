/*
    Design a HashSet without using any built-in hash table libraries.
    
    To be specific, your design should include these functions:
    
    add(value): Insert a value into the HashSet. 
    contains(value) : Return whether the value exists in the HashSet or not.
    remove(value): Remove a value in the HashSet. If the value does not exist in the HashSet, do nothing.
    
    Example:
    
    MyHashSet hashSet = new MyHashSet();
    hashSet.add(1);         
    hashSet.add(2);         
    hashSet.contains(1);    // returns true
    hashSet.contains(3);    // returns false (not found)
    hashSet.add(2);          
    hashSet.contains(2);    // returns true
    hashSet.remove(2);          
    hashSet.contains(2);    // returns false (already removed)
    
    Note:
    
    All values will be in the range of [0, 1000000].
    The number of operations will be in the range of [1, 10000].
    Please do not use the built-in HashSet library.
    
*/

#include "common.h"


/* based on bit set method */

class MyHashSet_based_on_bitset {
public:
    /** Initialize your data structure here. */
    MyHashSet_based_on_bitset() {
        
    }
    
    void add(int key) {
      if(key < 0 || key > 1000000) {
        return;
      }
      m_bit_set.set(key);
    }
    
    void remove(int key) {
      if(key < 0 || key > 1000000) {
        return;
      }    
      m_bit_set.reset(key);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
      if(key < 0 || key > 1000000) {
        return false;
      }    
      return m_bit_set.test(key) == 1;
    }

private:
  bitset<1000000> m_bit_set;
};

// based on basic vector

//int bit_map [64][2] = {
  
//};

class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
      uint64_t len = 1000000 / 32 + 1;
      m_bit_set.reserve(len);
      for(uint64_t i = 0; m_bit_set.size(); i++) {
        m_bit_set[i] = 0;
      }

      uint64_t temp = 1;
      for(int i = 0; i < 32; i++) {
        m_bit_map.push_back(temp << i);
        std::cout << (temp<<i) << std::endl;
      }
    }
    
    void add(int key) {
      auto index = get_index(key);    
      m_bit_set[index.first] |= m_bit_map[index.second];
    }
    
    void remove(int key) {
      auto index = get_index(key); 
      m_bit_set[index.first] &= ~m_bit_map[index.second]; 
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
      auto index = get_index(key);
      return m_bit_set[index.first] & m_bit_map[index.second];     
    }
private:
  
  pair<uint32_t, uint32_t> get_index(uint32_t key) {
    return pair<uint32_t, uint32_t>{key / 32, key % 32};
  }

  vector<uint32_t> m_bit_map;
  vector<uint32_t> m_bit_set;
};

// add 1
// add 2 
// contain 1
// contain 3

int main() {
  uint64_t xxx = 200 / 64;
  cout << "xxx : " << xxx << std::endl;
  MyHashSet temp;
  temp.add(1);
  temp.add(2);
  assert(temp.contains(1) == true);
  assert(temp.contains(2) == true);
  assert(temp.contains(3) == false);

  temp.add(1);
  temp.add(2);
  temp.add(100);
  temp.add(123);
  temp.add(12345);
  assert(temp.contains(100) == true);
  assert(temp.contains(123) == true);
  assert(temp.contains(12345) == true);

  temp.remove(123);
  assert(temp.contains(123) == false);
  assert(temp.contains(123) == false);

  std::cout << (1 | 2 | 4) << std::endl;
  return 0;
}



/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
