class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0]++;
        int s =0;
        int count=0;
        for(auto i: nums){
            i =  i%2;
            s+=i;
            if(mp.count(s-k)){
                count+= mp[s-k];
            }
            mp[s]++;
        }
        return count;
    }
};