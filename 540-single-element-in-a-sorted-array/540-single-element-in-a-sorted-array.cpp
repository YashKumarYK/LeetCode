class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        //approach 1 - bit manipulation - TC -O(n)
        // int ans =0;
        // for( int i=0; i< nums.size(); i++){
        //     ans = ans^ nums[i];
        // }
        // return ans;
        
        //APPROACH 2- Binary search
        int s=0;
        int e=nums.size()-1;
        int mid= s+(e-s)/2;
        
        if (nums.size()==1) return nums[0];
        if ( nums[0] !=nums[1]) return nums[0];
        else if( mid ==e && nums[e] !=nums[e-1]) return nums[e];
        
        while( s<=e){
            
            if (nums[mid]!= nums[mid+1] && nums[mid] !=nums[mid-1]) return nums[mid];
            
            else{ 
                if ( (mid%2 ==0 && nums[mid] == nums[mid+1] )|| (mid%2==1 && nums[mid-1]== nums[mid])){
                    s= mid +1;
                }
                else
                    e= mid-1;
            }         
             
            mid = s+(e-s)/2;
        }
        return -1;
    }
};