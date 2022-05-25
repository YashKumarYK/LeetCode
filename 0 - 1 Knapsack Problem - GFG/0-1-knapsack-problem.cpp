// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
   
    int T[1002][1002] ;
    
    int helper( int W, int wt[], int val[], int n){
       
       if( n ==0 || W==0) return 0;
       
       if( T[W][n] != -1){
           return T[W][n];
       }
       else if( wt[n-1] <= W){
           T[W][n] = max( val[n-1] + helper( W-wt[n-1], wt, val, n-1), helper(W, wt, val, n-1));
           return T[W][n];
            
           
       }
       else if( wt[n-1]> W){
           T[W][n] =helper(W, wt, val, n-1);
           return T[W][n];
       }
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       
       memset( T, -1, sizeof(T));
       return helper(W, wt, val, n);
       //recursion solution
       
            
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends