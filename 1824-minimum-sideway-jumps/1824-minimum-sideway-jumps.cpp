class Solution {
public:
    
    int solve(int lane, int ind, vector<int> &obstacle, vector<vector<int>> &dp){
        if( ind == obstacle .size()-1) return 0;      
        
        if( dp[ind][lane] !=-1) return dp[ind][lane];
        
        if( obstacle[ind+1] != lane) return solve( lane, ind+1, obstacle, dp);
        
        int mini = INT_MAX;
        for(int i=1; i<=3; i++){
            if( lane !=i && obstacle[ind] !=i){
                
                mini = min(mini,1+solve(i, ind, obstacle, dp));
                
            }
        }
        return dp[ind][lane] = mini;
    }
    int minSideJumps(vector<int>& obstacles) {
        vector<vector<int>> dp( obstacles.size(), vector<int> (4,-1));
        return solve(2, 0, obstacles, dp);
    }
};