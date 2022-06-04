// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int m = 1003;
    int solve( string &S, int i, int j, bool isTrue,vector<vector<vector<long long>>> &dp){
        if( i>j){
            return 0;
        }
        
        if( dp[i][j][isTrue] !=-1){
            return dp[i][j][isTrue];
        }
        //checking for the single element whether it is true or false
        if( i==j){
            // if we are looking for true
            if( isTrue == 1){
                return S[i]== 'T';
            }
            
            //if we are looking for false
            else{
                return S[i] =='F';
            }
        }
        
        long long ways =0;
        for( int k = i+1; k<=j-1; k=k+2){
            long long leftT = solve( S, i, k-1, 1, dp);
            long long leftF = solve( S, i, k-1, 0, dp);
            
            long long rightT= solve( S, k+1, j, 1, dp);
            long long rightF = solve( S, k+1, j, 0, dp);
        
            if( S[k] == '&'){
                //if looking for true
                if( isTrue) ways += ((leftT*rightT)%m)%m;
                
                else{
                    ways+= ((leftF*rightF)%m + (leftT*rightF)%m +(leftF*rightT)%m)%m;
                }
                
            }
            else if( S[k]=='|'){
                if( isTrue) ways += ((leftT*rightT)%m + (leftT*rightF)%m +(leftF*rightT)%m)%m;
            
                else{
                    ways += ((leftF * rightF)%m)%m;
                }
            }
            else{
                if (isTrue) ways+= ((leftT * rightF)%m + (leftF * rightT)%m)%m ;
            
                else{
                    ways +=( (leftF * rightF)%m + (leftT * rightT)%m)%m  ;
                }
            }
        }
        return dp[i][j][isTrue] =ways%m ;
    }
    int countWays(int N, string S){
        vector<vector<vector<long long>>> 
        dp( N, vector<vector<long long>>(N, vector<long long> (2, -1)));
        return solve( S, 0, N-1, 1, dp);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends