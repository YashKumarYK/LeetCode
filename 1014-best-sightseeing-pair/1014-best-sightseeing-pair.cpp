class Solution {
public:
    int dp[50002][2];
    int solve( vector<int> &values, int n , int ind, bool taken){
        if(ind ==n) return INT_MIN;
        if( dp[ind][taken] != -1) return dp[ind][taken];
        int first=0;
        if( taken==0){
            first = max( values[ind]+ ind + solve( values, n, ind+1, 1), solve( values, n, ind+1, 0));
        }
       
        else if( taken ==1){
            return  dp[ind][taken] = max(values[ind]-ind, solve( values, n, ind+1, 1));
        }
        return dp[ind][taken] = first;
    }
    
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        memset( dp , -1, sizeof(dp));
        return solve(values, n, 0, 0);
    }
};