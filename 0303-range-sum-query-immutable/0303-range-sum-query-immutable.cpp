class NumArray {
public:
    vector<int> preSum;
    NumArray(vector<int>& nums) {
        preSum.push_back(0);
        for( auto i: nums){
            preSum.push_back(i+preSum.back());
            cout<<preSum.back()<<" ";
        }
    }
    
    int sumRange(int left, int right) {
        return preSum[right+1]- preSum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */