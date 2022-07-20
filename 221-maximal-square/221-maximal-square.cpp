class Solution {
public:
    
    int solve( vector<vector<char>> &mat, int i, int j, vector<vector<int>> &dp, int&maxi){
        if( i==mat.size() || j==mat[0].size()) return 0;
        
        if( dp[i][j]!= -1) return dp[i][j];
        
        int right = solve( mat, i, j+1, dp, maxi);
        int diag = solve( mat, i+1, j+1, dp, maxi);
        int bottom = solve( mat, i+1, j, dp, maxi);
        if( mat[i][j]=='1'){
            int ans = 1+ min({right, diag, bottom});
            maxi= max( maxi, ans);
            
            return dp[i][j]= ans;
        }
        
        else{
            return dp[i][j]=0;
        }
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<vector<int>> dp( r+1, vector<int> (c+1, -1));
        int maxi=0;
        solve( matrix, 0,0, dp, maxi);
        
        return maxi*maxi;
    }
};