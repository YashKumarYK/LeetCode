class Solution {
public:
    
    int solve( vector<int> &st, int i, int t, vector<vector<int>> &dp){
        if( i==st.size()) return 0;
        if( dp[i][t] !=-1) return dp[i][t];
        
        int include = (t)* st[i] + solve( st, i+1, t+1, dp);
        int exclude = solve( st, i+1, t, dp);
        
        return dp[i][t]= max( include, exclude);
    }
    int maxSatisfaction(vector<int>& st) {
        int n = st.size();
        sort( st.begin(), st.end());
        if( st[n-1]<0) return 0;
        vector<vector<int>> dp( n+1, vector<int> (n+1, -1));
        return solve( st, 0, 1, dp);
    }
};