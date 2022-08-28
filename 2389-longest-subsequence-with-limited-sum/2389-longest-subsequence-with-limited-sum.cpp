class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> v( nums.size(), 0);
        // we have to take the maximum size subsequence. for that we have to use the smallest element.
        // this can be done  by sorting the nums first;
        
        sort( nums.begin(), nums.end());
        
        int sum =0;
        
        for( int i=0; i<nums.size(); ++i){
            sum += nums[i];
            v[i]= sum;
        }
        
        vector<int> ans;
        for( auto i: queries){
            int ind = upper_bound( v.begin(), v.end(), i) - v.begin();
            
            ans.push_back( ind);
        }
        return ans;
    }
};