class Solution {
public:
    long long m = 1e9+7;
    int maxArea(int h, int w, vector<int>& hcuts, vector<int>& vcuts) {
        sort(hcuts.begin(), hcuts.end());
        sort(vcuts.begin(), vcuts.end());
        
        int h_maxi = hcuts[0];
        int v_maxi = vcuts[0];
        for(int i=1; i<hcuts.size(); i++){
            h_maxi = max( h_maxi, hcuts[i]- hcuts[i-1]);
        }
        h_maxi = max(h_maxi, h- hcuts[hcuts.size()-1]);
        
        for(int i=1; i<vcuts.size();i++){
            v_maxi = max( v_maxi, vcuts[i]-vcuts[i-1]);
        }
        v_maxi = max( v_maxi , w- vcuts[vcuts.size()-1]);
        
        int ans = ((v_maxi%m) * (h_maxi%m))%m;
        return ans;
    }
};