class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n= nums.size();
        // if(nums[0]>x && nums[n-1]>x) return -1;
        int sum =0;
        for( int i=0; i<n; i++){
            sum+= nums[i];
        }
        
        int target = sum-x;
        if( target<0) return -1;
        if( target ==0) return n;
        int i=0; int j =0;
        sum =0;
        int len = 0;
        while( j< n){
            sum += nums[j];
            if( sum ==target){
                len= max(len, j-i+1);
            }
            else if( sum>target){
                while(sum>target){
                    sum -=nums[i];
                    i++;
                }
                if( sum ==target){
                len= max(len, j-i+1);
            }
            }
            j++;
        }
        if(len ==0) return -1;
        return n-len;
    }
};