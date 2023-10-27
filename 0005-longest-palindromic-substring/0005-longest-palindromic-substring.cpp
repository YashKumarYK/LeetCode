class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if( n ==1) return s;
        bool dp[n+1][n+1];
        int st= 0;
        int e= 0;
        //traversing through the gaps/ diagonals
        for( int g =0; g< n; ++g){
            for( int i=0, j=g; j<n; ++j, ++i){
                if( g==0) dp[i][j]=true;
                else if(g==1) dp[i][j] = s[i]==s[j];
                else{
                    if( s[i] == s[j] && dp[i+1][j-1] ==true){
                        dp[i][j] = true;
                    }
                    else{
                        dp[i][j] = false;
                    }
                }
                if(dp[i][j] == true){
                    st = i;
                    e = j+1;
                }
            }
        }
        return s.substr(st,e-st);
    }
};