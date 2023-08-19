class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int n = nums.size();
        set<int> s;
        int diff = INT_MAX;
        for(int i=x;i<n; i++){
            // inserting the element in the set
            s.insert(nums[i-x]);
            // findind the element which is just equal or greater to the nums[i]
            auto it = s.upper_bound(nums[i]);

            // we need to compare both  newrest smaller and nearest greater
            //for nearest greater
            if(it!= s.end()) diff = min(diff, abs(*it-nums[i]));
            
            // for nearest smaller
            if(it!= s.begin()) diff = min(diff, abs(*prev(it)-nums[i]));    
        }
        
        return diff;
    }
};