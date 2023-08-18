class Solution {
public:
    bool isValid(vector<int> &nums, int k, int Sum){
        int s = 0;
        int subArr =1;
        for( auto &i:nums){
            if(s+i<=Sum){
                s+= i;
            }else{
                subArr++;
                if(subArr>k || i>Sum) return false;
                s=i;

            }
        }
        return subArr<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int s = 0;
        int e = accumulate(nums.begin(), nums.end(),0);
        int ans = -1;
        while(s<=e){
            int m = s+(e-s)/2;
            if(isValid(nums, k , m)){
                ans = m;
                e = m-1;
            }else{
                s = m+1;
            }
        }
        return ans;
    }
};