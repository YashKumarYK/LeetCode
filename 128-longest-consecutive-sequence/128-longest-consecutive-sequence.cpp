class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int , greater<int>> s;
        for(int i=0; i<nums.size(); i++){
            s.insert(nums[i]);
        }
        if( nums.size()==0) return 0;
        int curr=1;
        int maxi=INT_MIN;
        vector<int> v;
        for(auto i:s){
            cout<< i<<" ";
            v.push_back(i);
        }
        for(int i=1; i<v.size(); i++){
            if( v[i] == v[i-1]-1){
                curr++;
            }
            else{
                maxi= max(curr, maxi);
                curr=1;
            }
        }
        maxi= max(curr, maxi);
        return maxi;
    }
};