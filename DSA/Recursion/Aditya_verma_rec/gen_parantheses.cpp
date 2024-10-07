/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
*/

class Solution {
public:

void solve(int open,int close,vector<string>&ans,string op)
{
    if(open==0&&close==0)
    {
        ans.push_back(op);
        return;
    }   
    
    if(open!=0)
    {
        string op1=op;
        op1.push_back('(');
        solve(open-1,close,ans,op1);
    }

    if(close>open)
    {
        string op2=op;
        op2.push_back(')');
        solve(open,close-1,ans,op2);
    }
    return;

}
    vector<string> generateParenthesis(int n) {
        int open=n,close=n;
        
        vector<string>ans;
        string op="(";
        solve(open-1,close,ans,op);
        return ans;

    }
};
