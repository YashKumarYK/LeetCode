class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, bool> map;
        for(int i=0; i<nums.size(); i++){
            if(map[nums[i]] == true){
                return true;
            }
            map[nums[i]]= true;
        }
        return false;
    }
};