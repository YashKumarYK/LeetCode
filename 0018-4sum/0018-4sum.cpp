class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j = i+1; j<n; j++){
                int s = j+1;
                int e = n-1;
                while(s<e){
                    long long sum = (long long) nums[i]+nums[j]+nums[s]+nums[e];
                    if(sum == target){
                        ans.push_back({nums[i], nums[j], nums[s], nums[e]});
                        // cout<<i<<" "<<j<<" "<<s<<" "<<e<<endl;
                        while(s<e && nums[s]== nums[s+1]) s++;
                        while(s<e && nums[e]==nums[e-1]) e--;
                        s++;
                        e--;
                    }
                    else if(sum < target){
                        s++;
                    }else{
                        e--;
                    }
                }
                while(j<n-1 && nums[j]==nums[j+1]) j++;
            }
            while(i<n-1 && nums[i]==nums[i+1]) i++;
        }
        return ans;
    }
};