//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    vector<int> v={1,2,5,10,20,50,100,200,500,2000};
    
    // int solve( int N, int n ){
    //     if( N==0) return 0;
    //     if(n<0) return INT_MAX;
    //     int notake = solve(N, n-1);
    //     int take = INT_MAX;
    //     if( N>=v[n-1]){
    //         take = 1+ solve(N-v[n-1], n);
    //     }
    //     return min(take, notake);
    // }
    vector<int> minPartition(int N)
    {
        vector<int> ans;
        // cout<<solve(N, 10);
        
        // vector<vector<int>> dp(10, vector<int> (N+1,0));
        // 
        int i =9;
        while( i>=0){
            if(N >= v[i]){
                while( N>=v[i]){
                    N-= v[i];
                    ans.push_back(v[i]);
                }
            }
            else{
                i--;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends