/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Logic: use map to store elements and if element -1 is find then cur element cant be starting sequence , search ofr start seq and keep max
*/


class Solution {
public:
    int longestConsecutive(vector<int>& a) {
      unordered_set<int>s;
      int ans=0,cnt=0;
      for(int i=0;i<a.size();i++)
          s.insert(a[i]);

      for(auto it:s)
        {
            if(s.find(it-1)==s.end())
            {
                cnt=1;
                int x=it;
                while(s.find(x+1)!=s.end())
                {
                    x=x+1;
                    cnt=cnt+1;
                }
                ans=max(ans,cnt);
            }
        }    
      return ans;

    }
};
