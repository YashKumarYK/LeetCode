class Solution {
public:
    int candy(vector<int>&  nums) {
        int n = nums.size();
        vector<int> ltr(n, 1);
        vector<int> rtl(n, 1);
        for(int i=1; i<n; i++){
            if( nums[i]> nums[i-1]){
                ltr[i] = ltr[i-1]+1;
            }
        }
        for(int i=n-2; i>=0; i--){
            if( nums[i]>nums[i+1]) {
                rtl[i] = rtl[i+1]+1;
            }
            
        }
        int sum =0;
        for(int i=0; i<n; i++){
            sum = sum+ max( rtl[i] , ltr[i]);
        }
        
        return sum;
    }
};