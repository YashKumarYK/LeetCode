class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> s;
        vector<int> minArr(nums.size());
        minArr[0] = nums [0];
        for(int i=1; i<nums.size(); i++){
            minArr[i] = min(nums[i], minArr[i-1]);
        }
        for(int j= nums.size()-1; j>=0; j--){
            if(nums[j]> minArr[j]){
                while(! s.empty() && s.top()<=minArr[j]){
                    s.pop();
                }
                if(!s.empty() && s.top()< nums[j] ){
                    return true;
                }
                s.push(nums[j]);
            }
        }
        return false;        
    }
};