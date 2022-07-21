bool comparator( vector<int> &a, vector<int> &b){
        if( a[0]== b[0]) return a[1]>b[1];
        return a[0]<b[0];
    }
class Solution {
public:
    
    int maxEnvelopes(vector<vector<int>>& env) {
        sort( env.begin(), env.end(), comparator);
        int n =env.size();
        vector<int> v;
        int len =1;
        v.push_back(env[0][1]);
        for(int i =0; i<n; ++i){
            
            if( v.back() <env[i][1]){
                v.push_back( env[i][1]);
                len++;
            }
            else{
                int ind = lower_bound(v.begin(), v.end(), env[i][1]) - v.begin();
                v[ind] = env[i][1];
            }
        }
        return len;
    }
};