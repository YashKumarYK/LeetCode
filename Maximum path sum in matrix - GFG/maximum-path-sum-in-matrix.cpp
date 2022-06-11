// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // int solve(int i, int j, int &N, vector<vector<int>> &Matrix, vector<vector<int>> &dp){
    //     if( j<0 ||j>N-1) return 0;
    //     if( i==N-1) return Matrix[i][j];
        
    //     if( dp[i][j] !=-1) return dp[i][j];
    //     int down = Matrix[i][j]+ solve( i+1, j, N, Matrix, dp);
    //     int diag1 = Matrix[i][j] + solve(i+1, j-1, N, Matrix, dp);
    //     int diag2 = Matrix[i][j]+ solve(i+1,j+1, N, Matrix, dp);
    //     return dp[i][j]=max({down, diag1, diag2});
    // }
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // int maxi=INT_MIN;
        // vector<vector<int>> dp(N+1, vector<int> (N+1,-1));
        // for(int j=0; j<N; ++j){
        //     maxi = max( maxi,solve( 0, j, N , Matrix, dp));
        // }
        // return maxi;
        if( N==1) return Matrix[0][0];
        int dp[N+1][N+1];
        for( int i=0; i<N; i++){
            for( int j=0; j<N; j++){
                dp[i][j]= Matrix[i][j];
            }
        }
        int maxi=0;
        for(int i=N-2; i>=0; i--){
            for(int j=0; j<N; j++){
                int down = dp[i][j]+ dp[i+1][j];
                int diag1=0, diag2=0;
                if( j-1>=0)
                    diag1 = dp[i][j] + dp[i+1][j-1];
                
                if( j+1<N)
                    diag2 = dp[i][j]+ dp[i+1][j+1];
                dp[i][j]=max({down, diag1, diag2});
                maxi = max(maxi, dp[i][j]);
            }
            
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