// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    int solve( int A[], int i, int N, vector<int> &dp){
        if( i>=N-1) return true;
        if( A[i]== 0) return false;
        // cout<<i<<"->";
        if( dp[i]!= -1) return dp[i];
        
        bool flag= false;
        for( int j = i+1; j<=min( N-1, i+ A[i]); j++){
            flag = flag || solve( A, j, N, dp);
            if( flag == 1) return dp[i]= 1;
        }
        return dp[i] = flag;
        
    }
    int canReach(int A[], int N) {
        vector<int> dp(N+1, -1);
        
        return solve( A, 0,N, dp);
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}  // } Driver Code Ends