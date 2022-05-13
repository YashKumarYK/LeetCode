class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> arr;
        for (int i=0;i<nums.size();i++){
            arr.push_back({nums[i], i}); 
        }
        int s=0;
        int e= nums.size()-1;
        sort(arr.begin(), arr.end());
        int idx1=0;
        int idx2=0;
        while(s<e){
            if((arr[s].first + arr[e].first) == target){
                idx1= arr[s].second;
                idx2= arr[e].second;
                break;
            }
            if((arr[s].first + arr[e].first) < target) s++;
            if((arr[s].first + arr[e].first)> target) e--;
        }
        return {idx1, idx2};
    }
};