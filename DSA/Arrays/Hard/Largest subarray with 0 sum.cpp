/*
Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

Examples:

Input: arr[] = {15,-2,2,-8,1,7,10,23}, n = 8
Output: 5
Explanation: The largest subarray with sum 0 is -2 2 -8 1 7.
Input: arr[] = {2,10,4}, n = 3
Output: 0
Explanation: There is no subarray with 0 sum.
Input: arr[] = {1, 0, -4, 3, 1, 0}, n = 6
Output: 5
Explanation: The subarray is 0 -4 3 1 0.
Expected Time Complexity: O(n).
Expected Auxiliary Space: O(n).

logic: use map and prefix sum
*/


class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
        
        unordered_map<int,int>m;
        
        int ans=0;
        int sum=0;
        
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            if(sum==0)
            {
                ans=max(ans,i+1);
            }
            
            else if(m.find(sum)!=m.end())
            {
                ans=max(ans,i-m[sum]);
            }
            else m[sum]=i;
            
            
        }
        return ans;
    }
};
