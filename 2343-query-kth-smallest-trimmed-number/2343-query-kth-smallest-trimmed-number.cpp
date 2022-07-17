class Solution {
public:
    
    int ksmall( vector<string>& nums, int j, int k){
        priority_queue<pair<string,int>> pq;
        int n = nums[0].size();
        
        for(int i=0; i<k; ++i){
            string s =nums[i].substr(n-j, j);
            pq.push({s, i});
        }
        for(int i=k; i<nums.size(); ++i){
            string s =nums[i].substr(n-j, j);
            if( pq.top().first > s){
                pq.pop();
                pq.push({s, i});
            }
        }
        return pq.top().second;
    }
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = nums[0].size();
        vector<int> ans;
        for( auto i: queries){        
            int k = i[0];
            int j = i[1];
            int ind = ksmall(nums,j, k);
            ans.emplace_back(ind);
        }
        return ans;
    }
};