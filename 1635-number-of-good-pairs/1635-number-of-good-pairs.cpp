class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto i: nums) mp[i]++;
        int cnt =0;
        for(auto i: mp){
            cnt+= (i.second-1)*(i.second)/2;
        }
        return cnt;
    }
};