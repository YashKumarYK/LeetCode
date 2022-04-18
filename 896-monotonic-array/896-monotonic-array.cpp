class Solution 
{
public:
    bool isMonotonic(vector<int>& nums) 
    {
        int n= nums.size();
        int s= 0;
        int e= 1;
        // if (nums[0]>nums[1]|| nums[0]>= nums[1]) flag =0;
        for(int i=2; i<n; i++)
        {
            if (nums[s]==nums[e]){
                s++;
                e++;
                if(nums.size()!=3)
                    i++;
            }
            if(((nums[s]>nums[e])&&(nums[i]>nums[i-1]))||((nums[s]<nums[e])&& (nums[i]<nums[i-1])))
                return false;
        }
        return true;
        // if (flag) return true;
        // else return false;  
    }
};