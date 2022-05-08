class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if ( nums.size()<=1){
            return 0;
        }
        
        vector<int> v;
        for( int i=0; i<nums.size(); i++){
            v.push_back( nums[i]);
        }
        sort(v.begin(), v.end());
        int s =nums.size()-1; 
        int e=0 ;
        for( int i =0 ;i<nums.size();i++){
            if(v[i] != nums[i]){
                s = min(s,i);
                e = max(s,i);
            }
        }
        if(e-s<0) return 0;
        else return e-s+1;
    }
};