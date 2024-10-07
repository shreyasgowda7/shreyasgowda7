/*
Given an integer N , Print all binary strings of size N which do not contain consecutive 1s.

A binary string is that string which contains only 0 and 1.
*/

//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

void solve(vector<string>&ans,int num,string op)
{
    if(num==0)
    {
        ans.push_back(op);
        return;
    }
    
        string op1=op;
        op1.push_back('0');
        solve(ans,num-1,op1);
    
    
    if(op.empty() || op.back()!='1')
    {   
        string op2=op;
        op2.push_back('1');
        solve(ans,num-1,op2);
    }
    
}
class Solution{
public:
    vector<string> generateBinaryStrings(int num){
        vector<string>ans;
        //ans.push_back(0);
        string op="";
        solve(ans,num,op);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        
        vector<string> v = obj.generateBinaryStrings(n);
        for(auto it:v) cout<<it<<" ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends
