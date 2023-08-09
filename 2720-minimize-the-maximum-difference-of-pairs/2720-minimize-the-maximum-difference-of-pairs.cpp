class Solution {
public:
    bool condition(int diff, vector<int> & nums, int pairs){
        int p = 0;
        for(int i=1;i<nums.size(); i++){
            if(nums[i]-nums[i-1]<=diff){
                p++;
                i++;
            }
        }
        return p>=pairs;

    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int s =0;
        int e = nums[n-1]-nums[0];
        int ans = INT_MAX;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(condition(mid, nums, p)){
                ans = mid;
                e = mid-1;
            }else{
                s = mid+1;
            }
        }
        return ans;
    }
};
