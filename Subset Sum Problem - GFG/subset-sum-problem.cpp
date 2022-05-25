// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{
    int dp[1000][1000];
public:
// recursive solution
    // with memoization
    
    // int solve( int n, vector<int> arr, int sum){
    //     if( sum == 0 ) return 1;
    //     if( n<=0){
    //         return 0;
    //     }
        
    //     if(dp[n][sum] != -1){
    //         return dp[n][sum];
    //     }
        
    //     else if( arr[n-1] <= sum){
    //         //we have choice whether tp include or not
    //         //include
    //         return dp[n][sum] = ( solve(n-1, arr, sum- arr[n-1]) || solve(n-1, arr, sum ));
    //     }
        
    //     else if( arr[n-1]> sum) {
    //         return dp[n][sum] =solve( n-1, arr, sum);
    //     }
    // }
    // bool isSubsetSum(vector<int>arr, int sum){
    //     int n = arr.size();
    //     memset(dp, -1, sizeof(dp));
    //     if(solve( n, arr, sum)){
    //         return true;
            
    //     }
    //     else return  false;
        
    // }
    
    //using dynamic programming
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        int dp[ n+1][sum+1];
        
        for( int i=0; i<n+1; i++){
            for( int j=0; j<sum+1; j++){
                if( i==0) dp[i][j] = false;
                if( j==0) dp[i][j] = true;
            }
        }
        
        for( int i=1; i<n+1; i++){
            for( int j=1; j<sum+1; j++){
                if( arr[i-1]<= j){
                    dp[i][j] = dp[i-1][j] || dp[i-1][j - arr[i-1]];
                }
                else if( arr[i-1]> j){
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends