class NumArray {
public:
    int v[10000];
    NumArray(vector<int>& nums) {
        int sum =0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            v[i]= sum;
        }
    }
    
    int sumRange(int left, int right) {
        int s1= v[right];
        int s2=0;
        if( left!=0) s2 = v[left-1];
        return s1-s2;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */