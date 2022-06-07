class Solution {
public:
    bool solve( string a, string b, unordered_map<string,bool> &mp){
        if( a.compare(b)==0) return true;
        if( a.length()<=1) return false;
        
        if( mp.find(a+"_"+b)!= mp.end()) return mp[a+"_"+b];
        int n = a.length();
        bool flag = false; // initiallly we are assuming the strings are not scrambled
        
        for( int i=1; i<=n-1; i++){
            //condition 1- when swap is done
            bool cond1 = solve(a.substr(0,i), b.substr(n-i, i), mp)&& solve(a.substr(i,n-i), b.substr(0,n-i), mp);
            
            //condition 2- when there is no swap
            bool cond2 = solve(a.substr(0,i), b.substr(0,i), mp) && solve(a.substr(i,n-i), b.substr(i,n-i), mp);
            
            if(cond1||cond2==true){
                flag =true;
                break;
            }
        }
        return mp[a+"_"+b] =flag;
    }
    bool isScramble(string s1, string s2) {
        if( s1.length()==0 && s2.length()==0)
            return true;
        if( s2.length()!= s2.length())
            return false;
        ///for memoization
        unordered_map<string, bool> mp;
        return solve( s1, s2, mp);
    }
};