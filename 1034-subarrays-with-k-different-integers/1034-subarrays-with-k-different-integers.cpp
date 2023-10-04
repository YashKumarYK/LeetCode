class Solution {
public:
    int subcount(vector<int>& nums, int k){
        int n= nums.size();
        unordered_map<int,int> mp;
        int i=0;
        int j=0;
        int count=0;
        while(j<n){
            mp[nums[j]]++;
            while(mp.size()>k){
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
            }
            if(mp.size()<=k){
                count+= j-i+1;
            }
            j++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subcount(nums, k) - subcount(nums, k-1);
    }
};