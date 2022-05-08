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
        int s =0; 
        int e= nums.size()-1;
        int max;
        int min;
        
        while(s<nums.size()){
            if(v[s] != nums[s]){
                min =s;
                break;
            }
            s++;
        }
        while(e>=0){
            if(v[e] != nums[e]){
                max =e;
                break;
            }
            e--;
        }
        if(max-min +1<0) return 0;
        else return max-min+1;
    }
};