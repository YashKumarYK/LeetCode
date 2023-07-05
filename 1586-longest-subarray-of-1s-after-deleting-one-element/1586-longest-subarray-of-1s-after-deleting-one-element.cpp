class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        int prevlen = -1;
        int prevend = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                int start = i;
                while(i<n-1 && nums[i+1]==1){
                    i++;
                }
                int currlen = i-start+1;
                if(prevend!= -1 && prevend+2 == start){
                    maxi = max(maxi, prevlen+currlen);
                }
                maxi = max(currlen, maxi);

                prevend = i;
                prevlen = currlen;
            }
        }
        if(maxi == n) maxi--;
        return maxi;
    }
};