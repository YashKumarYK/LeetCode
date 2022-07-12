class Solution {
public:
    
    int minSwaps(vector<int>& nums) {
        int n= nums.size();
        if( n==1) return 0;
        
        int cnt =0;
        for(int i=0; i<n; i++){
        
            if( nums[i]==1) cnt++;
        }
        
        for(int i=0; i<n; i++){
            nums.push_back( nums[i]);
        }
        
        n = nums.size();
        if(cnt==0) return 0;
        
        int i=0, j=0;
        int mini = INT_MAX;
        int sum =0;
        while( j<n){
            sum+= nums[j];
            if( j-i+1== cnt){
                mini = min(mini,cnt - sum);
                
                sum -= nums[i];
                i++;
            }
            j++;
        }
    
        return mini; 
    }
};