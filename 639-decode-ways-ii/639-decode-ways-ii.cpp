class Solution {
public:
    int m = 1e9+7;
    long long solve( string &s, int i, vector<int> & dp){
        if( i == s.size()) return 1;
        if( s[i]=='0') return 0;
        
        if( dp[i]!= -1) return dp[i];
        long long a1 = solve( s,i+1, dp);
        if( s[i]=='*'){
            a1= a1*9;
        }
        long long a2=0;
        if( i<s.size()-1){
            
            if( s[i]=='*' && s[i+1]=='*')
                a2= 15* solve(s, i+2, dp);
            
            else if( (s[i]=='1' || s[i]=='2') && s[i+1]=='*')
                a2= (s[i]=='1'?9:6)*solve(s, i+2, dp);
            
            else if(s[i]=='*' && s[i+1]<'7')
                a2= 2*solve(s, i+2, dp);
            
            else if( s[i]=='1' || (s[i]=='2' &&s[i+1]<'7'))
                a2= solve( s, i+2, dp);
            else if( s[i]=='*')
                a2= solve( s, i+2, dp);
        }
        
        return dp[i] = (a1%m+a2%m)%m;
    }
    int numDecodings(string s) {
        vector<int> dp( s.size()+1, -1);
        return solve( s, 0, dp);
    }
};