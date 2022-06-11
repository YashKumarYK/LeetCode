// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int i, int j, int &N, vector<vector<int>> &Matrix, vector<vector<int>> &dp){
        if( j<0 ||j>N-1) return 0;
        if( i==N-1) return Matrix[i][j];
        
        if( dp[i][j] !=-1) return dp[i][j];
        int down = Matrix[i][j]+ solve( i+1, j, N, Matrix, dp);
        int diag1 = Matrix[i][j] + solve(i+1, j-1, N, Matrix, dp);
        int diag2 = Matrix[i][j]+ solve(i+1,j+1, N, Matrix, dp);
        return dp[i][j]=max({down, diag1, diag2});
    }
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        int maxi=INT_MIN;
        vector<vector<int>> dp(N+1, vector<int> (N+1,-1));
        for(int j=0; j<N; ++j){
            maxi = max( maxi,solve( 0, j, N , Matrix, dp));
        }
        return maxi;
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends