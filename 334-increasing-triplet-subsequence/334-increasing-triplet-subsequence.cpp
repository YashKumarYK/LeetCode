class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int left = INT_MAX;
        int middle = INT_MAX;
        for( auto i: nums){
            if( left >= i){
                left =i;
            }
            else if( middle >=i){
                middle = i;
            }
            else {
                return true;
            }
        }
        return false;
    }
};