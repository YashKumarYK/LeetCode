class Solution {
public:
    
    int solve( vector<int> &days, vector<int> &costs, int ind, vector<int> &dp){
        if( ind == days.size()) return 0;
        
        if( dp[ind] != -1) return dp[ind];
        //for 1 days trip
        int trip1 = costs[0] + solve( days, costs, ind+1, dp);
        
        //for 7 days trip
        int ind2 = lower_bound( days.begin(), days.end(), days[ind]+7)- days.begin();
        int trip7 = costs[1] + solve( days, costs, ind2, dp);
        
        //for 30 days. trip
        int ind3 = lower_bound( days.begin(), days.end(), days[ind]+ 30)- days.begin();
        int trip30 = costs[2]+ solve( days, costs, ind3, dp);
        
        return dp[ind] = min({trip1, trip7, trip30});
        
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp( days.size(), -1);
        return solve( days, costs, 0, dp);
    }
};