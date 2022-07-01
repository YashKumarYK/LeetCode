class Solution {
public:
    
    int solve( int i, int j , vector<vector<int>> &matrix, vector<vector<int>> &dp){
        if( j<0 ||j>=matrix.size()) return 1e7;
        if( i==matrix.size()-1) return matrix[i][j];
        
        if( dp[i][j]!= -1) return dp[i][j];
        
        int score = matrix[i][j];
        int a = solve( i+1, j-1, matrix, dp);
        int b = solve( i+1, j, matrix, dp);
        int c = solve( i+1, j+1, matrix, dp);
        return dp[i][j] = score+ min({a, b, c});
        
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int mini = INT_MAX;
        vector<vector<int>> dp( n, vector(n, -1));
        for( int i=0; i<n ; i++){
            mini = min( mini, solve( 0,i, matrix, dp));
        }
        return mini;
    }
};