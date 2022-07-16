class Solution {
public:
    
    int solve( vector<int> &v, int ind, int e, vector<vector<int>> &dp){
        if( ind+1>=e) return 0;
        
        if( dp[ind][e] != -1) return dp[ind][e];
        
        int mini= INT_MAX;
        for(int k = ind+1; k<e; k++){
            int cost = v[ind]*v[e]*v[k] + solve(v, ind, k, dp) + solve( v, k, e, dp);
            mini = min( mini, cost);
        }
        return dp[ind][e] = mini;
    }
    int minScoreTriangulation(vector<int>& v) {
        int n = v.size();
        if( n==3) return v[0]*v[1]*v[2];
        vector<vector<int>> dp( n, vector<int> (n, -1));
        return solve( v, 0, n-1, dp);
        
        
    }
};