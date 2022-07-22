class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> v; 
        int count =0;
        for(int i=0; i<nums.size(); i++){
            if( nums[i]< pivot){
                v.push_back(nums[i]);
            }
            if( pivot== nums[i]) count++;
        }
        
        while( count--){
            v.push_back( pivot);
        }
        
        for(int i=0; i<nums.size(); i++){
            if( nums[i]> pivot){
                v.push_back(nums[i]);
            }
        }
        
        return v;
    }
};