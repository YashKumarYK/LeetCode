class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<pair<int,int>> p;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                int start = i;
                while(i<n-1 && nums[i+1]==1){
                    i++;
                }
                // cout<<i-start+1<<endl;
                p.push_back({start, i-start+1});
            }
        }
        if(p.size()==0) return 0;
        
        int maxi =p[0].second;
        if(maxi== n) return maxi-1;
        for(int i=1;i<p.size(); i++){
            if(p[i-1].first+p[i-1].second+1== p[i].first){
                maxi = max(maxi, p[i-1].second + p[i].second);
            }
            maxi = max({maxi, p[i-1].second, p[i].second});

        }
        return maxi;
    
    }
};