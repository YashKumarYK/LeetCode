class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        vector<int> t(2);
        
//         t= intervals[0];
//         if( newInterval[0] < intervals[0][0]){
//             t= newInterval;
//         }
//         for(auto i:intervals){
//             if( newInterval[0]<= i[1]){
                
//             }
//             else{
//                 ans.push_back(v);
//             }
//         }
        intervals.push_back( newInterval);
        sort(intervals.begin(), intervals.end());
        
        t= intervals[0];
        for(auto i:intervals){
            if( t[0]<= newInterval[0] && t[1]>= newInterval[0]){
                t[1]= max( t[1], newInterval[1]);
            }
            if( t[1]>= i[0]){
                t[1] = max( t[1], i[1]);
            }
            
            else{
                ans.push_back(t);
                t= i;
            }
        }
        ans.push_back(t);
        return ans;
    }
};