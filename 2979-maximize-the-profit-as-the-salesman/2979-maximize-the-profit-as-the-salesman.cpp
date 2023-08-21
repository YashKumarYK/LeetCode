class Solution {
public:
vector<int> dp;
    int solve(int ind, vector<vector<int>>& offers, vector<int> &start){
        if(ind>= offers.size()) return 0;
        if(dp[ind]!= -1) return dp[ind];
        int index = lower_bound(start.begin(), start.end(), offers[ind][1]+1)-start.begin();
        int pick = 0;
        pick = offers[ind][2] + solve(index,offers, start);
        int nopick = solve(ind+1, offers, start);
        
        return dp[ind] = max(pick, nopick);
    }
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(), offers.end());
        vector<int> start;
        for(auto &i:offers) start.push_back(i[0]);
        dp.resize(offers.size(), -1);
        return solve(0, offers, start);
    }
};