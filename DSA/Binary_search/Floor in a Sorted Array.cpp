//
Given a sorted array arr[] of size n without duplicates, and given a value x. Floor of x is defined as the largest element k in arr[] such that k is smaller than or equal to x. Find the index of k(0-based indexing).

Examples

Input: n = 7, x = 0 arr[] = {1,2,8,10,11,12,19}
Output: -1
Explanation: No element less than 0 is found. So output is "-1".
Input: n = 7, x = 5 arr[] = {1,2,8,10,11,12,19}
Output: 1
Explanation: Largest Number less than 5 is 2 (i.e k = 2), whose index is 1(0-based indexing).
Your Task:
The task is to complete the function findFloor() which returns an integer denoting the index value of K or return -1 if there isn't any such number.

Expected Time Complexity: O(log N).
Expected Auxiliary Space: O(1).
  
//


class Solution {
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> &nums, long long n, long long x) {
        int ans=-1; int l=0,r=n-1;
        
        while(l<=r)
        {   
            int m = (r+l)/2;

            if(nums[m]==x)
            return m;

            if(nums[m]<x)
            {
                ans=m;
                l=m+1;
            }
             
            else
            r=m-1;
        }
        return ans;
        
    }
};
