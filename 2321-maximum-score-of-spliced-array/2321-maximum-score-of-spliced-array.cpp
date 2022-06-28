class Solution {
public:
    
    int solve( vector<int> &nums1, vector<int> &nums2){
        int n = nums1.size();
        vector<int> diff(n);
        for( int i=0; i<n; i++){
            diff[i] = nums1[i] - nums2[i];
        }
        
        int maxsum = INT_MIN;
        int currsum = 0;
        
        for(int i=0; i<n; i++){
            currsum += diff[i];
            if( currsum > maxsum){
                maxsum = currsum;
            }
            if( currsum <0){
                currsum =0;
            }
        }
        if(maxsum<=0) return 0;
        return maxsum;
    }
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate( nums2.begin(), nums2.end(),0);
        int Amaxi = max(sum2 +solve(nums1, nums2) , sum1+ solve(nums2, nums1));
        
        return Amaxi;
    }
};