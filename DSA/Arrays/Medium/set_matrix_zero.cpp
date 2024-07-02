/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

Logic: use 2 maps, for r and c. and keep track of 0;
*/


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        unordered_map<int,int>r;
        unordered_map<int,int>c;

        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    r[i]=1;
                    c[j]=1;
                }
            }
        }

        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                if(r[i]==1 || c[j]==1)
                {
                  matrix[i][j]=0;
                }
            }
        }



    }
};
