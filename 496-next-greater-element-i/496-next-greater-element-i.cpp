class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        int n1 = nums1.size();
        int n2 = nums2.size();
        map<int, int> mp;
        s.push(-1);
        for( int i=n2-1; i>=0; --i){
            while( s.top()!=-1 && s.top()<nums2[i]){
                s.pop();
            }
            mp[nums2[i]] = s.top();
            s.push(nums2[i]);
        }
        
        vector<int> ans( n1, 0);
        for( int i=0; i<n1; ++i){
            ans[i] = mp[nums1[i]];
        }
        
        return ans;
    }
};