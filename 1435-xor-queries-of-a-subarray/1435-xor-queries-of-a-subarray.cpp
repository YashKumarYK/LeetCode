class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> XV(n+1,0);
        int xr = 0;
        for(int i=0;i<n; i++){
            xr^=arr[i];
            XV[i+1] = xr;
        }
        vector<int> ans;
        for( auto q: queries){
            int r = q[1], l = q[0];
            ans.push_back(XV[r+1]^XV[l]);
        }
        return ans;
    }
};