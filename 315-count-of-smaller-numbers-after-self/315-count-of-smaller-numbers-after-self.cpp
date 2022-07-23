class Solution {
public:
    const int N = 2e4 + 1;
    vector<int> bit;
    void update(int i, int delta) {
        for(; i < N; i = i | (i + 1) ) bit[i] += delta;
    }
    int sum(int i) {
        int res = 0;
        for(; i >= 0; i = (i & (i + 1)) - 1)    res += bit[i];
        return res;
    }
    vector<int> countSmaller(vector<int>& nums) {
        bit.resize(N);
        int n = nums.size();
        vector<int> ans(n);
        for(int i = n - 1; i >= 0; --i) {
            nums[i] += 10000;
            ans[i] = sum(nums[i] - 1);
            update(nums[i], 1);
        } 
        return ans;
    }
};