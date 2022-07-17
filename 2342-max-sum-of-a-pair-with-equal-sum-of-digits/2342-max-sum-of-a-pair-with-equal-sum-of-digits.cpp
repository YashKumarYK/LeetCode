class Solution {
public:
    
    int digitsum( int n){
        int sum =0;
        while( n!=0){
            sum += n%10;
            n/=10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        int ans =-1;
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            //finding the sum of digits
            int temp = digitsum( nums[i]);
            
            if( mp.find(temp) != mp.end()){
                if( mp[temp] + nums[i]> ans){
                    
                    ans = mp[temp] + nums[i];
                }
                
                mp[temp] = max( mp[temp], nums[i]);
            }
            
            else{
                mp[temp]= nums[i];
            }
        }
        
        return ans;
    }
};