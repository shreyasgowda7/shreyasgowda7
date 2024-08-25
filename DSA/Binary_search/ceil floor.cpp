/*
Given an unsorted array arr[] of integers and an integer x, find the floor and ceiling of x in arr[].

Floor of x is the largest element which is smaller than or equal to x. Floor of x doesn’t exist if x is smaller than smallest element of arr[].
Ceil of x is the smallest element which is greater than or equal to x. Ceil of x doesn’t exist if x is greater than greatest element of arr[].

Return an array of integers denoting the [floor, ceil]. Return -1 for floor or ceiling if the floor or ceiling is not present.

Examples:

Input: x = 7 , arr[] = [5, 6, 8, 9, 6, 5, 5, 6]
Output: 6, 8
Explanation: Floor of 7 is 6 and ceil of 7 is 8.
Input: x = 10 , arr[] = [5, 6, 8, 8, 6, 5, 5, 6]
Output: 8, -1
Explanation: Floor of 10 is 8 but ceil of 10 is not possible.

Logic: use binary search , for optimal use vector of 2 length and store compare elememnt with target for ceil floor


*/



class Solution {
  public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
       /* 
        int floor=-1,ceil=-1; int l=0,r=nums.size()-1;
        sort(nums.begin(), nums.end());
        while(l<=r && r>=0)
        {   
            int m = (r+l)/2;

            if(nums[m]==x)
            return {x,x};

            if(nums[m]<x)
            {
                floor=nums[m];
                l=m+1;
            }
             
            else
            {
             ceil=nums[m];        
             r=m-1;
            }
        }
        return {floor,ceil};
        */
         vector<int> a(2 ,-1);
        bool flag=1;
        a[1]=INT_MAX;
        
        
        for(int i=0; i<arr.size(); i++)
        {
             if(arr[i]<=x && arr[i]>a[0])
             a[0]=arr[i];
             
             if(arr[i]>=x  && arr[i]<a[1])
             {
                 a[1]=arr[i];
                 flag=0;
             }
        }
        
        if(flag)
        a[1]=-1;
        return a;
    
    }
};
