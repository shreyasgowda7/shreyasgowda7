/*
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4


Logic: return mid if found or else left, because loop terminates when left > r so it is in correct place to insert
*/



class Solution {
public:
    int searchInsert(vector<int>& nums, int t) {
         int l=0,r=nums.size()-1;
         while(l<=r)
        {   
            int m = (r+l)/2;

            if(nums[m]==t)
            return m;

            if(nums[m]<t)
            l=m+1;
            else
            r=m-1;
        }
        return l;
    }
};
