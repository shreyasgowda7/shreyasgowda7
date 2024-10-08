/*
Given a stack, delete the middle element of the stack without using any additional data structure.

Middle element:- floor((size_of_stack+1)/2) (1-based indexing) from the bottom of the stack.

Note: The output shown by the compiler is the stack from top to bottom.

Examples:

Input: stack = [10, 20, 30, 40, 50]
Output: [10, 20, 40, 50]
Explanation: The bottom-most element will be 10 and the top-most element will be 50. Middle element will be element at index 3 from bottom, which is 30. Deleting 30, stack will look like {10 20 40 50}.
*/

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to delete middle element of a stack.
    
    void del(stack<int>&s,int mid)
    {
        if(mid==1)
        {
            s.pop();
            return;
        }
        
        int t=s.top();
        s.pop();
        del(s,mid-1);
        s.push(t);
        return;
    }
    void deleteMid(stack<int>& s, int sizeOfStack) {
       
       int mid=floor(sizeOfStack+1)/2;
       del(s,mid);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int sizeOfStack;
        cin >> sizeOfStack;

        stack<int> myStack;

        for (int i = 0; i < sizeOfStack; i++) {
            int x;
            cin >> x;
            myStack.push(x);
        }

        Solution ob;
        ob.deleteMid(myStack, myStack.size());
        while (!myStack.empty()) {
            cout << myStack.top() << " ";
            myStack.pop();
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
