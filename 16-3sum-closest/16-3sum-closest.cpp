class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = nums[0]+nums[1]+nums[2];
        int mini=INT_MAX; 
        for(int i=0; i<n; i++){
            if( i!= 0 && nums[i]== nums[i-1]){
                continue;
            }
            
            int s=i+1;
            int e = n-1;
            while(s<e){
                int sum =nums[i]+ nums[s]+nums[e];
                if( sum> target){
                    e--;
                }
                else if( sum<target){
                    s++;
                }
                else{
                    while( s<e && nums[s+1]==nums[s]) s++;
                    while(s<e && nums[e]==nums[e-1]) e--;
                    s++;
                    e--;
                }
                if(abs(target- ans)>=abs(target- sum)){
                    ans = sum;
                }
            }
        }
        return ans;
    }
};