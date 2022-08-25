class Solution {
public:
    vector<int> v;
    vector<int> rand;
    
    Solution(vector<int>& nums) {
        v= nums;
        rand= nums;
    }
    
    vector<int> reset() {
        return v;
    }
    
    vector<int> shuffle() {
        next_permutation(rand.begin(), rand.end());
        return rand;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */