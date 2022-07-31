class NumArray {
public:
    vector<int> seg;
    int n=0;
    void build( vector<int> &nums, int ind, int low, int high){
        if( low ==high){
            seg[ind] = nums[low];
            return;
        }
        int mid = (high+low)>>1;
        build( nums, 2*ind+1, low, mid);
        build( nums, 2*ind+2, mid+1, high);
        
        seg[ind]= seg[ 2*ind+1] + seg[2*ind+2];
    }
    
    int query( int ind, int l, int r, int low, int high){
        //no overlapping
        if( l>high || r<low){
            return 0;
        }
        
        //complete overlapping
        if( l<=low && r>=high){
            return seg[ind];
        }
        
        int mid = (high+low)>>1;
        // if( idx<=mid) 
        int left = query( 2*ind+1, l, r, low, mid);
        int right = query( 2*ind+2, l, r, mid+1, high);
        
        return left+ right;
    }
    
    void valupdate( int ind, int val, int idx, int low, int high){
        if( low == high){
            seg[ind] = val;
            return;
        }
        
        int mid = (high+low)>>1;
        
        if( idx<=mid)
            valupdate( 2*ind+1, val, idx, low, mid);
        else{
            valupdate(2*ind+2, val, idx, mid+1, high);
        }
        
        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
        
    }
    NumArray(vector<int>& nums) {
        n= nums.size();
        seg.resize(4*n+1);
        build( nums, 0, 0, n-1);
    }
    
    
    void update(int index, int val) {
        // for( int i=0; i<4*n; i++) cout<< seg[i]<<" ";
        valupdate( 0, val, index, 0, n-1);
        // cout<<endl;
        // for( int i=0; i<4*n; i++)  cout<< seg[i]<<" ";
        // cout<<endl;
    }
    
    int sumRange(int left, int right) {
        return query( 0, left, right, 0, n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */