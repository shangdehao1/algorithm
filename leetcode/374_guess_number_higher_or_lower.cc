/*
 * 
 * We are playing the Guess Game. The game is as follows:
 * 
 * I pick a number from 1 to n. You have to guess which number I picked.
 * 
 * Every time you guess wrong, I'll tell you whether the number is higher or lower.
 * 
 * You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):
 * 
 * -1 : My number is lower
 *  1 : My number is higher
 *  0 : Congrats! You got it!
 * Example :
 * 
 * Input: n = 10, pick = 6
 * Output: 6
 * 
 */


// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);


int guessNumber(int n) {
  int left = 1;
  int right = n;

  while (left <= right) {
    long long mid = (right - left) / 2 + left;
    int ret = guess(mid);
    if (ret == 0) {
      return mid;
    } else if (ret == -1) {
      left = mid + 1;
    } else if (ret == 1) {
      right = mid -1;
    } else {
      assert(-1);
    }
  }

  return left;
}













