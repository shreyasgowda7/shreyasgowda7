/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]

Logic: moore voting only but here max 2 candidate can be there
*/


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        vector<int>ans;
        int cand1=-1,cand2=-2;
        int n=nums.size();
        int count1=0,count2=0;
        for(int i=0;i<nums.size();i++)
        {
            if(count1==0 && nums[i]!=cand2)
            {
                cand1=nums[i];
                count1++;
            }
            else if(count2==0 && nums[i]!=cand1)
            {
                cand2=nums[i];
                count2++;
            }
            else if(cand1==nums[i])
            {
                count1++;
            }
            else if(cand2==nums[i])
            {
                count2++;
            } 
            else 
            { 
                count1--;
                count2--;
            }    
        }
        count1 = 0, count2 = 0;

        for(int i=0;i<n;i++)
        {
            if(nums[i]==cand1)
            count1++;
            if(nums[i]==cand2)
            count2++;
        }

        if(count1 > (n/3) ) 
          ans.push_back(cand1);
        
        if(count2 > (n/3)) 
          ans.push_back(cand2);

        return ans;
    }
};
