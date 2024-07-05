/*
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2


Logic: Use map to store prefix sum and find if sum is present
*/


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      int prefixsum=0,count=0;
      unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
        { 
           prefixsum+=nums[i];

           if(prefixsum==k)
           count++;

           if(m.find(prefixsum-k)!=m.end())
           {
            count+=m[prefixsum-k];
           }
            m[prefixsum]++;
            
        }

       return count; 
    
    }
};
