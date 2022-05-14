class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        
        //approach #1 - using map 
        // map<int, int> m;
        // for(int i=0; i<nums.size();i++){
        //     if( m[nums[i]]==1) res.push_back(nums[i]);
        //     m[nums[i]]++;
        // }
        // return res;
        
        //approach #2 after sorting
        sort(nums.begin(), nums.end());
        for( int i=0 ;i<nums.size()-1; i++){
            if( nums[i]==nums[i+1]){
                res.push_back(nums[i]);
                i++;
            }
            
        }
        return res;
    }
};