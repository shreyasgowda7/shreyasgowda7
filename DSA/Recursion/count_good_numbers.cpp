/*
A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).

For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) at odd positions are prime. However, "3245" is not good because 3 is at an even index but is not even.
Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 109 + 7.

A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.

 

Example 1:

Input: n = 1
Output: 5
Explanation: The good numbers of length 1 are "0", "2", "4", "6", "8".
Example 2:

Input: n = 4
Output: 400
Example 3:

Input: n = 50
Output: 564908303
 

Constraints:

1 <= n <= 1015


Logic:  5 even nums and 4 prime nums in 0 to 9, 5 ^ number 0f even place * 4 ^ number of odd place
*/

class Solution {
public:
    const int mod= 1e9+7;
    long long powers(long long x,long long n)
    {
        if(n==0)
        return 1;
        if(n%2==0)
        {
            
            return powers((x*x)%mod,n/2);
        }
        else return (x*powers(x,n-1))%mod;
    }
    
    int countGoodNumbers(long long n) {
       long long numberOfOddPlaces = n/2;
        long long numberOfEvenPlaces = n/2 + n%2;
        long long evenResult = powers(5, numberOfEvenPlaces);
        long long oddResult = powers(4, numberOfOddPlaces);
        long long ans= (evenResult*oddResult)%mod;
        return ans;
    }
};
