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
    
    
    int solve( int n, vector<int> arr, int sum){
        if( sum == 0 ) return 1;
        if( n<=0){
            return 0;
        }
        
        if(dp[n][sum] != -1){
            return dp[n][sum];
        }
        
        else if( arr[n-1] <= sum){
            //we have choice whether tp include or not
            //include
            return dp[n][sum] = ( solve(n-1, arr, sum- arr[n-1]) || solve(n-1, arr, sum ));
        }
        
        else if( arr[n-1]> sum) {
            return dp[n][sum] =solve( n-1, arr, sum);
        }
    }
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        memset(dp, -1, sizeof(dp));
        if(solve( n, arr, sum)){
            return true;
            
        }
        else return  false;
        
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