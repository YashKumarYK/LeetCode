class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& in) {
        int n = in.size();
        vector<int> ans;
        unordered_map<int,int> mp;
        vector<int> v1;
        int ind=0;
        for( auto i: in){
            v1.push_back( i[0]);
            mp[i[0]]=ind++;
        }
        sort( v1.begin(), v1.end());
        
        for( auto i: in){
            
            if(i[1]> v1[n-1]) ans.push_back(-1);
            else{
                int ind = lower_bound( v1.begin(), v1.end(), i[1])- v1.begin();
                ans.push_back(mp[v1[ind]]);
            }    
        }
        
        return ans;
    }
};