class Solution {
public:
    int newx[4]= {1, -1, 0, 0};
    int newy[4]= {0, 0, -1, 1};
    int mode = 1e9+7;
    
    int solve( int m , int n, int maxMove, int i,int j,vector<vector<vector<int>>> &dp ){
        if( i<0 ||j<0 ||i==m||j==n) return 1;
        if( maxMove ==0) return 0;
        
        if(dp[i][j][maxMove]!=-1) return dp[i][j][maxMove];
        long long  count =0;
        for(int k=0; k<4; k++){
            int x = newx[k]+i;
            int y = newy[k]+j;
            count = count%mode + solve(m, n, maxMove-1, x, y, dp)%mode;
        }
        
        return dp[i][j][maxMove] =count%mode;
    }
    int findPaths(int m, int n, int maxMove, int i, int j) {
        
        vector<vector<vector<int>>> dp( m+1, vector<vector<int>>( n+1, vector<int> (maxMove+1, -1)));
        return solve( m, n, maxMove, i, j, dp);
    }
};