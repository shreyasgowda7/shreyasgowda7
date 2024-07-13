/*
Given an integer array nums, find a 
subarray
 that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

 

Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.


logic: 2 traversal r to l and l to r, because if even neg numbers are there, entire array is max but when odd neg numbers are there, 1 neg has to be left out, there will be 2 subarrays l and r part so both direction traversal
*/




class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        double cur=nums[0],maxy=nums[0],maxz=nums[nums.size()-1];

        for(int i=1;i<nums.size();i++)
        {
            if(cur==0)
            cur=1;
           cur=cur*nums[i];
           
            maxy=max(maxy,cur);

        }
cur=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--)
        {
            if(cur==0)
            cur=1;
            cur=cur*nums[i];
           
            maxz=max(maxz,cur);

        }
        return max(maxy,maxz);
        
    }
    
};
