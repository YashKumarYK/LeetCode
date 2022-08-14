class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        vector<int> v( n+1, 0);
        for( int i=0; i<=n; i++){
            v[i]= i;
        }
        
        for( int i=0; i<n ; i++){
            if( s[i]=='I'){
                continue;
            }
            if( s[i]=='D'){
                int j = i+1;
                while( s[j]=='D'){
                    j++;
                }
                // cout<<i<<" "<<j;
                reverse( v.begin()+i, v.begin()+ j+1);
                i=j-1;
            }
            // cout<<i<<" ";
        }
        return v;
    }
};