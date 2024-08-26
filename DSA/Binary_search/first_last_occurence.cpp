/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]


Logic:

first occurence, if element found shift left to find first occr
last occur, if element found shift right to find last occr
*/



class Solution {
public:

int firstOcc(vector<int>& nums, int x){
        int low = 0, high = nums.size()-1;
        int ans = -1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] == x){
                ans = mid;
                high = mid - 1;
            }
            else if(nums[mid] > x){
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }

    int lastOcc(vector<int>& nums, int x){
        int low = 0, high = nums.size()-1;
        int ans = nums.size();
        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] == x){
                ans = mid;
                low = mid + 1;
            }
            else if(nums[mid] > x){
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        
        int first = firstOcc(nums, target);
        if(first == -1) return {-1, -1};
        int last = lastOcc(nums, target);
        return {first, last};
    }
};
