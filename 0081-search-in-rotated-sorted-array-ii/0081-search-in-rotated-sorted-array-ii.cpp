class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0;
        int e = nums.size()-1;
        while(s<=e){
            int m = s+(e-s)/2;
            if(nums[m]==target) return true;
            if(nums[s]==nums[m] && nums[m]==nums[e]){ //for cases like [1,1,1,1,2,1,1] target = 2;
                s++;
                e--;
            }
            else if(nums[s]<=nums[m]){  // left part is sorted
                //check if target exists or not
                if(nums[s]<= target && target<= nums[m]){
                    e = m-1;
                }else{
                    s = m+1;
                }
            }
            else{// right part is sorted
                //check if target exists or not
                if(nums[m]<= target && target<= nums[e]){
                    s = m+1;
                }else{
                    e = m-1;
                }
            }
        }
        return false;
    }
};