class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int s = 1;
        int e = *max_element(nums.begin(), nums.end());
        int ans = -1;
        while(s<=e){
            int m = s+(e-s)/2;
            long long t = 0;
            for( auto &i: nums){
                t += (i+m-1)/m;
            }
            if(t<=threshold){
                ans =m;
                e = m -1;
            }else{
                s = m +1;
            }
        }
        return ans;
    }
};