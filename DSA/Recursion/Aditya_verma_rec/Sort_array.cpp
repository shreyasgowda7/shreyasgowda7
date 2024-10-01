/*
Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.

Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).

*/

class Solution {
public:

    void insert(vector<int>&nums,int temp)
    {
       if(nums.size()==0 || temp>nums[nums.size()-1])
       {
        nums.push_back(temp);
        return;
       }
        
       int val=nums[nums.size()-1];
       nums.pop_back();
       insert(nums,temp);
       nums.push_back(val);
       return; 

    }

    vector<int> sortArray(vector<int>& nums) {
        
        if(nums.size()==1)
        {
            return nums;
        }
        int temp=nums[nums.size()-1];
        nums.pop_back();
        sortArray(nums);
        insert(nums,temp);
        return nums;

    }
};

