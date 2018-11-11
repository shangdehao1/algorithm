/*
 * Given a non negative integer number num. 
 *
 * For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.
 * 
 * Example 1:
 * 
 * Input: 2
 * Output: [0,1,1]
 *
 * Example 2:
 * 
 * Input: 5
 * Output: [0,1,1,2,1,2]
 *
 * Follow up:
 * 
 * It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
 * Space complexity should be O(n).
 * Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
 * 
 * 2 ---> 0 1 2  --> 0 1 1 
 * 5 ---> 0 1 2 3 4 5 --> 0 1 1 2 1 2 
 * 
 */


// method 1 : bitset 
vector<int> countBits_1(int num) {
  vector<int> results;
  for (int i = 0; i <= num; i++) {
    bitset<64> temp(i);
    results.push_back(temp.count());
  }     
  return results;
}


// method 2: loop + testing the last bit 
// n n*n
vector<int> countBits_2(int num) {

  auto testing_bit_num = [](int num) {
    int result = 0;
    while (num != 0) {
      if((num & 1) != 0) {
        result++;
      }
      num = num >> 1;
    }
    return result;
  };

  vector<int> results;
  for (int i = 0; i <= num; i++) {
    results.push_back(testing_bit_num(i));
  }

  return results;
}


// method 3 : dynamic program.
// n n 
vector<int> countBits_3(int num) {
  vector<int> results(num + 1, 0);

  for (int i = 1; i <= num; ++i) {
    ret[i] = results[i&(i-1)] + 1;
  }

  return ret;
}







