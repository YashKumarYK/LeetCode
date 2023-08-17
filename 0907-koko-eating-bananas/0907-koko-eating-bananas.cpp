class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1;
        int e = 1e9+7;
        int ans = -1;
        while(s<=e){
            int m = s+(e-s)/2;
            long long h1 = 0;
            for(auto p: piles){
                h1+= ceil( 1.0*(double)p/(double)m);
            }
            if(h1<=h){
                ans = m;
                e = m-1;
            }else{
                s = m+1;
            }
        }
        return ans;
    }
};