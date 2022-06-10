class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> set1(nums1.begin(), nums1.end());
        set<int> set2(nums2.begin(), nums2.end());
        vector<int> ans1;
        vector<int> ans2;
        
        for(auto x: set1){
            if( set2.count(x)!=0){
                continue;
            }
            ans1.push_back(x);
        }
        
        for(auto i: set2){
            if(set1.count(i)!= 0)
                continue;
            ans2.push_back(i);
        }
        
        return {ans1, ans2};
    }
};