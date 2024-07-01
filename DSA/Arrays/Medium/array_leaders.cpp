/*
Given an array arr of n positive integers, your task is to find all the leaders in the array. An element of the array is considered a leader if it is greater than all the elements on its right side or if it is equal to the maximum element on its right side. The rightmost element is always a leader.

Examples

Input: n = 6, arr[] = {16,17,4,3,5,2}
Output: 17 5 2
Explanation: Note that there is nothing greater on the right side of 17, 5 and, 2.
Input: n = 5, arr[] = {10,4,2,4,1}
Output: 10 4 4 1
Explanation: Note that both of the 4s are in output, as to be a leader an equal element is also allowed on the right. side

Logic : Traverse from right and keep track of max
*/

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(int n, int arr[]) {
        int maxy =arr[n-1];
        vector<int>ans;
        ans.push_back(arr[n-1]);
        for(int i=n-2;i>=0;i--)
        {
            if(arr[i]>=maxy)
            {
              maxy=arr[i];
              ans.push_back(maxy);
            } 
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
