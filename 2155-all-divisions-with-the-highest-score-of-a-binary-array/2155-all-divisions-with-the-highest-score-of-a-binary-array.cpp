class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n+1 ,0);
        
        vector<int> suff( n+1, 0);
        int s1 =0;
        int s2 =0;
        for( int i=0; i<n; i++){
            
            suff[n-i] = s2;
            if( nums[i]==0){
                s1++;
            }
            s2+= nums[n-i-1];
            pre[i+1] = s1;
        }
        suff[0] = s2;
        
        
        map<int, vector<int>> mp;
        int maxi =0;
        for( int i=0; i<n+1; i++){
            int s= pre[i]+ suff[i];
       
            maxi = max( s, maxi);
            mp[s].push_back(i);
        }
        
        return mp[maxi];
    }
};