class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& in) {
        int n = in.size();
        vector<int> ans(n);
        map<int,int> mp;
        int ind=0;
        for( auto i: in){
            mp[i[0]]=ind++;
        }
        
        ind =0;
        for( auto i: in){
            ans[ind++]=  mp.lower_bound(i[1])!= mp.end()? mp.lower_bound(i[1])->second: -1;
        }
        
        return ans;
    }
};