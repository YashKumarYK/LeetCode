class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(auto i: nums) mp[i]++;
        int len=0;
        for(auto i: mp){
            if(mp.count(i.first-1)) continue;
            int num = i.first;
            while(mp.count(num)){
                num++;
            }
            len = max(len, num-i.first);
        }
        return len;
    }
};