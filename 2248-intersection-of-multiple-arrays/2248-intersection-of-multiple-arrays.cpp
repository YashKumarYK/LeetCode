class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> v;
        map<int, int> mp;
        for( int i=0; i<nums.size(); i++){
            for( int j=0; j<nums[i].size(); j++){
                mp[nums[i][j]]++;
                
                if( mp[nums[i][j]]==nums.size()){
                    v.push_back(nums[i][j]);
                }
                

            }
        }
        sort(v.begin(), v.end());
        return v;
    }
};