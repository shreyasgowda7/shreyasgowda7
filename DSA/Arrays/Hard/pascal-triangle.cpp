/*
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:

Input: numRows = 1
Output: [[1]]

Logic: sol 1) val of current row index elem = sum 0f prev row 2 index elem

sol 2) use formula r-1 C n-1 to generate
*/


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>>ans;
      
        for(int i=0;i<numRows;i++)
        {
           vector<int>temp(i+1,1);
            for(int j=1;j<i;j++)
            {   
               temp[j]=ans[i-1][j-1]+ans[i-1][j];;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};




class Solution {
public:
    vector<int> genrow(int i)
    {   
        vector<int>temp;
        int ans=1;
        temp.push_back(ans);

        for(int j=1;j<i;j++)
        {
            ans=ans*(i-j);
            ans=ans/j;
            temp.push_back(ans);
        }
        return temp;
    }
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>>ans;
        
        for(int i=1;i<=numRows;i++)
        {
            ans.push_back(genrow(i));
        }
        return ans;
    }
};
