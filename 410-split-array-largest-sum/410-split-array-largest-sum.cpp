class Solution {
public:
    
    
    bool condition(vector<int> &nums, int m, int maxsum){
        int elem =1;
        int currsum =0;
        for( int i=0; i<nums.size();++i){
            
            if(currsum+nums[i]>maxsum){
                elem++;
                if( elem>m) return false;
                currsum =nums[i];
            
            }else{
                currsum+= nums[i];
            }
            
        }
        return true;
        
    }
    int splitArray(vector<int>& nums, int m) {
        int sum = accumulate( nums.begin(), nums.end(), 0);
        int s = *max_element( nums.begin(), nums.end());
        int e= sum;
        
        int ans =0;
        while(s<=e){
            int mid = s+(e-s)/2;
            if( condition( nums, m, mid)){
                ans = mid;
                e = mid -1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};