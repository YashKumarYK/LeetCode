class Solution {
public:
    int solve(string &s1, string &s2, int n, int m, vector<vector<int>> &dp){
        if(n==0 || m==0) return 0;

        if(dp[n][m]!= -1) return dp[n][m];

        //if equal
        if(s1[n-1]== s2[m-1]){
            return dp[n][m] = int(s1[n-1]) + int(s2[m-1]) + solve(s1, s2, n-1, m-1, dp);
        }
        else{
            return dp[n][m] = max( solve(s1, s2, n-1, m, dp), solve(s1, s2, n, m-1, dp));
        }

    }
    int minimumDeleteSum(string s1, string s2) {
        int sum =0;
        for(auto i: s1){
            sum += int(i);
        }
        for(auto i: s2){
            sum += int(i);
        }
        vector<vector<int>> dp(s1.size()+1 , vector<int> (s2.size()+1, -1));
        return sum -solve(s1, s2, s1.size(), s2.size(), dp);
    }
};