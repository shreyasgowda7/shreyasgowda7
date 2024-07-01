/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]


Logic: Use Maps to store values
  */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size=nums.size();
        map<int,int>m;
        vector<int>ans;
         int i=0;
        for(i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        
        int val;
        for(i=0;i<nums.size();i++)
        {
            m[nums[i]]--;
            if(m[target-nums[i]]>0)
            {
                ans.push_back(i);
                val=target-nums[i];
                break;
            }
        }
         i++;
        while(i<nums.size())
        {
            if(val==nums[i])
            {
                ans.push_back(i);
                break;
            }
                 i++;    
        }
        return ans;
    }
};
