class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        if( sum <x) return -1;
        
        sum = sum-x;
        if( sum ==0) return n;
        
        int s =0, i=0, j=0, len =0;
        
        while( j<n){
            s+= nums[j];
            if( s==sum){
                len = max( len , j-i+1);
            }
            if( s> sum){
                while(s>sum){
                    s-= nums[i];
                    ++i;
                }
                if( s== sum){
                    len = max(len, j-i+1);
                }
            }
            j++;
        }
        
        return len==0? -1 : n-len;
    }
};