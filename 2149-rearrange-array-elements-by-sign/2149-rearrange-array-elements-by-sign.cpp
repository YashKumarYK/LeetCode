class Solution {
public:
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
        
        int j =0;
        int k =0;
        for(int i=0; i<nums.size(); i++){
            if( i%2==0){
                nums[i]=a[j++];
            }
            else{
                nums[i]= b[k++];
            }
        }
        return nums;
    }
};