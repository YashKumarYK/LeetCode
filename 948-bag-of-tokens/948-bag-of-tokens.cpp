class Solution {
public:
    int bagOfTokensScore(vector<int>& v, int power) {
        int n = v.size();
        sort(v.begin(), v.end());
        int i=0, j= n-1;
        int ans=0;
        int maxi =0;
        if( v.size()==0 || v[0]> power) return 0;
        while( i<=j){
            if( power >= v[i] && i<=j){
                ans++;
                power-= v[i];
                i++;
              
            }
            else if( power< v[i] && i<=j){
                ans--;
                power+= v[j];
                j--;
            }
            maxi = max( maxi,ans);
        }
        return maxi;
    } 
};