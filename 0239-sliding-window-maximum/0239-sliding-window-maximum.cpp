class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        list<int> l;
        
        vector<int> ans;
        int i=0;
        int j=0;
        
        while( j<nums.size()){
            
            while( !l.empty() && l.back()<nums[j]){
                l.pop_back();
            }
            
            l.push_back(nums[j]);
            
            if( j-i+1 ==k){
                ans.emplace_back(l.front());
                
                //moves right by one position
                if( nums[i]== l.front()){
                    l.pop_front();
                }
                ++i;
            }
            j++;
        }
        return ans;
    }
};