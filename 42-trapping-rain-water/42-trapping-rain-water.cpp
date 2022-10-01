class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> l(n), r(n);
        int m1 = height[0], m2 = height[n-1];
        for( int i=0; i<n; ++i){
            m1 = max( m1, height[i]);
            m2 = max( m2 , height[n-1-i]);
            l[i] = m1, r[n-1-i] =m2;
        }
        
        int cap =0;
        for( int i=0; i<n; i++){
            cap += min( l[i], r[i])- height[i];
        }
        return cap;
    }
};