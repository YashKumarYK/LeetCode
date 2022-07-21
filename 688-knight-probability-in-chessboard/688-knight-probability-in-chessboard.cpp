class Solution {
public:
    int diffx[8] = { -2, -2, 2, 2, -1, -1, 1, 1};
    int diffy[8] = { -1, 1, 1, -1, -2, 2, 2, -2};
    
    double solve( int i, int j , int k, int n, vector<vector<vector<double>>> &dp){
        if( i<0 ||j<0 || i>=n ||j>=n) return 0;
        if( k==0) return 1;
        
        if( dp[i][j][k] != -1) return dp[i][j][k];
        double count =0;
        for(int t=0; t<8; t++){
            int x = diffx[t] + i;
            int y = diffy[t] + j;
            count += solve( x, y, k-1, n, dp);
        }
        return dp[i][j][k]= count;
    }
    double knightProbability(int n, int k, int row, int column) {
        int i= row, j=column;
        vector<vector<vector<double>>> dp( n+1, vector<vector<double>> (n+1, vector<double> (k+1, -1)));
        
        return solve( i, j, k, n, dp)/ pow(8,k);
    }
};