/*
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

 

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10

logic: if mid odd, decrement and make it even check mid mid+1 euqal then left side is even 
*/


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        // Initialize the left and right pointers
        int l = 0;
        int r = nums.size() - 1;

        while (l < r) {
            // Set the value of mid
            int mid = l + (r - l) / 2;

            // If mid is odd, decrement it to make it even
            if (mid % 2 == 1) {
                mid--;
            }

            // If the elements at mid and mid + 1 are the same,
            // then the single element must appear after the midpoint
            if (nums[mid] == nums[mid + 1]) {
                l = mid + 2;
            }
            // Otherwise, we must search for the single element before the
            // midpoint
            else {
                r = mid;
            }
        }

        return nums[l];
    
    }
};
