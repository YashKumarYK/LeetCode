class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& nums) {
        unordered_map<double,int> mp;
        for(auto i: nums){
            double r= double(i[0]*1.)/ (double)(i[1]);
            mp[r]++;
        }
        long long cnt =0;
        for(auto i: mp){
            cnt+= (long long)(i.second-1)*(i.second)/2;
        }
        return cnt;
    }
};