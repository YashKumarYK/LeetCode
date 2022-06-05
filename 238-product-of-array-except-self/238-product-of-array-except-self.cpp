class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod=1;
        int n = nums.size();
        int zflag =0;
        for(auto i:nums){
            if(i==0){
                zflag++;
            }
            if( i !=0)
                prod *= i;
        }
        vector<int> ans (n, prod);
        for(int i=0; i<n; i++){
            if( nums[i]!=0)
                ans[i] = ans[i]/nums[i];
            if( zflag!=0){
                ans[i]=0;
            }
            if( zflag ==1 && nums[i]==0){
                ans[i]= prod;
            }
        }
        return ans;
    }
};