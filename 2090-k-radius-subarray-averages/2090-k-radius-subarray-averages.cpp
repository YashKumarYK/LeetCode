class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> ans( nums.size(), -1);
        
        int i=0;
        int j=0;
        int K = 2*k+1;
        long long sum =0;
        while( j<nums.size()){
            sum += nums[j];
            if( j-i+1==K){
                ans[i+k]= sum/K;
                
                sum-= nums[i];
                i++;
            }
            j++;
        }
        return ans;
    }
};