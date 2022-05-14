class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<int> v;
        vector<vector<int>> ans;
        
        if( intervals.size()==0) return ans;
        
        sort(intervals.begin(), intervals.end());
        
        v = intervals[0]; 
        for( auto i: intervals){
            if( v[1] >=  i[0]){
                v[1] = max( i[1], v[1]);
            }
            else{
                ans.push_back(v);
                v= i;
            }
        }
        ans.push_back(v);
        return ans;
    }
};