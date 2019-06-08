/*
 * Valid Perfect Square
 * 
 * Given a positive integer num, write a function which returns True if num is a perfect square else False.
 * 
 * Note: Do not use any built-in library function such as sqrt.
 * 
 * == Example 1: ==
 * 
 * Input: 16
 * Output: true
 * 
 * 
 * == Example 2: ==
 * 
 * Input: 14
 * Output: false
 * 
 */


namespace math_method {

bool isPerfectSquare(int num) {
    if(num < 0) return false;
  long index = 1;
  while (num > 0) {
      num -= index;
      index += 2;
  }

  return num == 0;
}

}

public boolean isPerfectSquare(int num) {
        int low = 1, high = num;
        while (low <= high) {
            long mid = (low + high) >>> 1;
            if (mid * mid == num) {
                return true;
            } else if (mid * mid < num) {
                low = (int) mid + 1;
            } else {
                high = (int) mid - 1;
            }
        }
        return false;
    }


namespace binary_search {

bool isPerfectSquare(int num) {
  int left = 1;
  int right = num;
  while (left <= right) {
    int mid = (low + high) >> 1;

    if (mid * mid == num) {
      return true; 
    } else if (mid * mid < num) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return false;
}

}


namespace depth_search {


bool depth_search(int num, long long left, long long right) {
  if (left > right) {
    return false;
  }

  long long mid = (left + right) >> 1;
  
  if (mid* mid == num) {
    return true;
  }

  if (mid * mid < num) {
    return depth_search(num, mid + 1, right);
  }

  return depth_search(num, left, mid - 1);
}


bool isPerfectSquare(int num) {
  return depth_search(num, 1, num);
}

}













