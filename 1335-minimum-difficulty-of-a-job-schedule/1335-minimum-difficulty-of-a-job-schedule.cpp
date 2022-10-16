class Solution {
public:
    
    int solve( vector<int> &jd, int n , int i, int d, vector<vector<int>> &dp){
        if( d== 1){
            return *max_element(jd.begin()+i, jd.end());
        }
        if(dp[i][d]!= -1) return dp[i][d];
        int maxi = INT_MIN;
        int result =INT_MAX;
        for( int ind=i; ind<=n-d; ++ind){
            maxi = max( maxi, jd[ind]);
            result = min( result,maxi+solve(jd, n, ind+1, d-1, dp));
        }
        
        return dp[i][d] = result;
    }
    
    int minDifficulty(vector<int>& jd, int d) {
        int n = jd.size();
        vector<vector<int>> dp( n+1, vector<int> (d+1, -1));
        int ans = solve( jd, n, 0, d, dp);
        return ans==INT_MAX? -1 : ans;
    }
};