class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<bool> isprime(n+1, true);
        for(int i=2;i<n;i++){
            if(isprime[i]){
                for(int j= i*2; j<n; j=j+i){
                    isprime[j]= false;
                }
            }
        }
        vector<vector<int>>ans;
        for(int i=2;i<=n/2;i++){
            if(isprime[i] && isprime[n-i]){
                ans.push_back({i, n-i});
            }
        }
        return ans;
    }
};