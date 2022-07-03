class Solution {
public:
    void solve( vector<int> a, vector<int> b, vector<int> &ans){
        int j =0;
        int k =0;
        for(int i=0; i<ans.size(); i++){
            if( i%2==0){
                ans[i]=a[j++];
            }
            else{
                ans[i]= b[k++];
            }
        }
    }
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> a;
        vector<int> b;
        for(int i=0; i<nums.size(); i++){
            if( nums[i]>=0){
                a.push_back(nums[i]);
            }
            else{
                b.push_back(nums[i]);
            }
        }
        
        solve(a, b, nums);
        return nums;
    }
};