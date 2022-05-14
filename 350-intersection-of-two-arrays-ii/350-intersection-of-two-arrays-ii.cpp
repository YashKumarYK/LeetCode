class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int tmp[1001]={0};
        vector<int> res;
        
        for(int i:nums1){
            ++tmp[i];
        }
        
        for(int i:nums2){
            if (tmp[i]>0)res.push_back(i);
            --tmp[i];
        }
        
        return res;
    }
};