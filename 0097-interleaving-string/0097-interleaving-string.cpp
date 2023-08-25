class Solution {
public:
    
    bool solve( string s1, string s2, string s3, int m, int n1, int n2,vector<vector<vector<int>>> &dp ){
        if( n1 ==0 && n1==n2) return true;

        if( m ==0) return false;

        if( dp[m][n1][n2]!= -1) return dp[m][n1][n2];
        
        if( n1==0){
            if( s3[m-1]== s2[n2-1]){
                if( solve(s1, s2, s3,m-1, n1, n2-1, dp))
                    return dp[m][n1][n2]= true;
            }
        }
        
        if( n2==0){
            if( s3[m-1]== s1[n1-1]){
                if( solve(s1, s2, s3,m-1, n1-1, n2, dp))
                    return dp[m][n1][n2]=true;
            }
        }
        
        if( n2!=0 && s3[m-1] == s2[n2-1]){
            if(solve( s1, s2, s3, m-1, n1, n2-1, dp)){
                return dp[m][n1][n2]= true;
            }
        }
        
        if( n1!=0 && s3[m-1] == s1[n1-1]){
            if(solve( s1,s2,s3,m-1, n1-1, n2, dp))
                return dp[m][n1][n2]= true;
        }
        
        return dp[m][n1][n2]= false;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size(), n2= s2.size(), m = s3.size();
        
        if( m!= n2+n1) return false;
        
        vector<vector<vector<int>>> dp( m+1, vector<vector<int>> (n1+1, vector<int>(n2+1, -1)));
        
        return solve( s1, s2, s3, m, n1, n2, dp);
    }
};