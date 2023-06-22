class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int f=0;
        int s =0;
        for( int i=n-1; i>=0; i--){
            int t=  max(f, nums[i]+s);
            s=f;
            f =t;
        }
        return f;
    }
};