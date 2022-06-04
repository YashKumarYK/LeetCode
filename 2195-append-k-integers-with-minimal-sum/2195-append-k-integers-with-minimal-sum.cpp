class Solution {
public:
    long long tsum( long long n){
        return n*(n+1)/2;
    }
    long long minimalKSum(vector<int>& nums, int k) {
        sort( nums.begin(), nums.end());
        int n = nums.size();
        int prev =0;
        long long sum =0;
        for( auto &curr : nums){
            if( k==0){
                return sum;
            }
            
            int count = min(k,curr- prev-1);
            if( count>0){
                long long currsum = tsum( prev+count);
                long long prevsum = tsum( prev);
                sum += currsum-prevsum;
                k -= count;
            }
            prev = curr;
        }
        
        // if k is still not equal to zero
        sum += tsum( nums[n-1] +k) - tsum(nums[n-1]);
        return sum;
    }
};