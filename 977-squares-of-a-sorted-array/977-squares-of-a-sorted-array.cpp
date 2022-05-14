class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int s =0; 
        vector<int> v = nums;
        int e = nums.size()-1;
        int k =nums.size()-1;
        while( s<=e){
            if( abs(nums[s]) >=abs(nums[e]))
            {
                v[k]= nums[s]*nums[s];
                s++;
            }
            else{
                v[k]= nums[e]*nums[e];
                e--;
            }
            k--;
        }
        return v;
    }
};