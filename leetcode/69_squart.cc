/*
 * Sqrt(x)
 * 
 * Implement int sqrt(int x).
 * 
 * Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
 * 
 * Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.
 * 
 * == Example 1: ==
 * 
 * Input: 4
 * Output: 2
 * 
 * == Example 2: ==
 * 
 * Input: 8
 * Output: 2
 * Explanation: The square root of 8 is 2.82842..., and since 
 *              the decimal part is truncated, 2 is returned.
 * 
 */



 int mySqrt(int x) {
        
        int left=1;
        int right=x/2;
        
        int last_mid;
        
        if (x<2) {
            return x;
        }
        
        while (left<=right) {
            const int mid=left+(right-left )/2;
            if (x/mid>mid) {
                left=mid+1;
                last_mid=mid;
            } else if(x/mid <mid) {
                right=mid-1;
            }else{
                return mid;
            }
        
        }
        return last_mid;
        
        
        
        
    }









