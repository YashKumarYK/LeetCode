class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int xr = 0;
        int n = pref.size();
        for(int i=0; i<n; i++){
            int v = pref[i];
            pref[i] = xr^pref[i];
            xr = v;
        }
        return pref;
    }
};