class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // int prod=1;
        // int n = nums.size();
        // int zflag =0;
        // for(auto i:nums){
        //     if(i==0){
        //         zflag++;
        //     }
        //     if( i !=0)
        //         prod *= i;
        // }
        // vector<int> ans (n, prod);
        // for(int i=0; i<n; i++){
        //     if( nums[i]!=0)
        //         ans[i] = ans[i]/nums[i];
        //     if( zflag!=0){
        //         ans[i]=0;
        //     }
        //     if( zflag ==1 && nums[i]==0){
        //         ans[i]= prod;
        //     }
        // }
        // return ans;
        int n = nums.size();
        vector<int> v(n);
        int prod=1;
        for(int i=0; i<n;i++){
            v[i]= prod;
            prod*= nums[i];
        }
        prod =1;
        for( int i=n-1; i>=0; i--){
            int temp = nums[i];
            nums[i]= prod;
            prod*= temp;
        }
        
        for( int i=0; i<n; i++){
            v[i]= v[i]* nums[i];
        }
        return v;
    }
};