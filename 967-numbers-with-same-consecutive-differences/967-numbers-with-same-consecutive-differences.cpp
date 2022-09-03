class Solution {
public:
    
    void solve( int n , int k ,int ind, set<int> &v, string s){
        if( ind == n-1){
            v.insert( stoi(s));
            return;
        }
        int a = s[ind]-'0';
        if( a-k>=0 ){
            solve( n, k, ind+1, v, s+to_string(a-k));
        }
        if(a+k<=9){
            solve(n, k, ind+1, v,s+to_string(a+k));
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> v;
        set<int> s1;
        for( int i=1; i<=9; ++i){
            string s = to_string(i);
            solve( n, k ,0, s1, s);
        }
        for( auto i: s1){
            v.push_back(i);
        }
        return v;
    }
};