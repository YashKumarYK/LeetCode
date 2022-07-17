class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int n = numsDivide.size();
        int ans = numsDivide[0];
        
        for(int i=1; i<n; i++){
            ans = __gcd(ans, numsDivide[i]);
        }
        
        sort( nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
            if( ans< nums[i]) break;
            if( ans%nums[i]==0) return i;
        }
        
        return -1;
        
    }
};