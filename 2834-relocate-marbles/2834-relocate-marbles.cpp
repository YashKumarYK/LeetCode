class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& mf, vector<int>& mt) {
        unordered_map<int,int> mp;
        for( auto i: nums){
            mp[i]++;
        }
        
        for( int i=0; i<mf.size(); i++ ){
            if(mp.count(mf[i])){
                int total = mp[mf[i]];
                mp.erase(mf[i]);
                mp[mt[i]] = total;
            }
        }

        vector<int> ans;
        for(auto i: mp){
            ans.push_back(i.first);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};