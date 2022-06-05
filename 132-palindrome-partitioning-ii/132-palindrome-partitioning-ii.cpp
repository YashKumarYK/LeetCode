class Solution {
public:
    bool ispalindrome( string &s, int i, int j){
        while( i<j){
            if( s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int solve( int index, int n, string &s, vector<int> &dp){
        //base case
        if( index ==n) return 0;
        
        if( dp[index] != -1) return dp[index];
        
        //main part
        int mini = INT_MAX;
        
        for(int j =index ; j<n; j++){
            if( ispalindrome( s, index, j)){
                int cost = 1+ solve( j+1, n, s, dp);
                mini = min(mini, cost);
            }
        }
        return dp[index] =mini;
    }
    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n,-1);
        
        return solve(0, n, s, dp)-1;   
    }
};