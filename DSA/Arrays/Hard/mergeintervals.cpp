/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

Logic: sort array and compare second index element with next first
*/



class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());
        int i=0;

        while(i<intervals.size()-1)
        {
          if(intervals[i][1]>=intervals[i+1][0])
          {
            intervals[i][1]=max(intervals[i][1],intervals[i+1][1]);
            intervals.erase(intervals.begin()+i+1);

          }
          else i++;

        }
        return intervals;

    }
};
