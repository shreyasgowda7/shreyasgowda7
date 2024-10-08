/*
Problem statement
You are given an array 'A' of 'N' integers. You have to return true if there exists a subset of elements of 'A' that sums up to 'K'. Otherwise, return false.



For Example
'N' = 3, 'K' = 5, 'A' = [1, 2, 3].
Subset [2, 3] has sum equal to 'K'.
So our answer is True.
*/

bool solve(int i, int k, vector<int> a, int sum)
 {
  if (sum == k) {
      return true;
  }
  
  if(a.size()==0 || sum>k)
  return false;
   
   int op1=sum;
   op1=op1+a[0];
   int op2=sum;
   a.erase(a.begin()+0);
   
   if(solve(i+1,k,a,op1)) return true;
   if(solve(i+1,k,a,op2)) return true;

return false;
   
 }
bool isSubsetPresent(int n, int k, vector<int> &a)
{
    int sum=0;
    return solve(0,k,a,0);
}
