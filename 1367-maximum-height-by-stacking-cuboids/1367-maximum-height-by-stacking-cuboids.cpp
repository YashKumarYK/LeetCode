class Solution {
public:
    int solve(int ind, int prev, vector<vector<int>> & cuboids, vector<vector<int>> &dp){
        if(ind==cuboids.size()) return 0;
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];

        if(prev==-1 || (cuboids[ind][1]>=cuboids[prev][1] && cuboids[ind][2]>=cuboids[prev][2])){
            int pick = cuboids[ind][2] + solve(ind+1, ind, cuboids, dp);
            int nopick = solve(ind+1, prev, cuboids, dp);
            return dp[ind][prev+1] = max(pick, nopick);
        }
        else{
            return dp[ind][prev+1] = solve(ind+1, prev, cuboids, dp);
        }
        
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        for( auto &i: cuboids){
            sort(i.begin(), i.end());
        }
        sort(cuboids.begin(), cuboids.end());
        vector<vector<int>> dp(n+1, vector<int> (n+2,-1));
        return solve(0, -1, cuboids, dp);
    }
};
