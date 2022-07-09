class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n= nums.size();
        if( n==1&& k%2==1) return -1;
        int maxi= -1;
        if( k==0) return n>=1?nums[0]:-1;
        if(k==1) return n==1? -1:  nums[1];
        
        int m = min((k-1), n);
        for(int i=0; i<m; i++){
            maxi = max( nums[i], maxi);
        }
        if( k<n){
            maxi = max( nums[k], maxi);
        }
        return maxi;
    }
};