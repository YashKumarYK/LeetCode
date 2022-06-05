class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        if(n==0) return ans;
        if( nums[0]> 0) return ans;
        if( n<3) return ans;
        // for( int i =0; i<n; i++){
        //     if( i!=0 && nums[i]== nums[i-1]){
        //         continue;
        //     }
        //     int target = -nums[i];
        //     int s =i+1;
        //     int e = n-1;
        //     while( s<e){
        //         if( nums[s]+nums[e] >target){
        //             e--;
        //         }
        //         else if(nums[s]+nums[e]<target){
        //             s++;
        //         }
        //         else{
        //             ans.push_back({nums[i], nums[s], nums[e]});
        //             while(e>s && nums[e] == nums[e-1]){
        //                 e--;
        //             }
        //             while( s<e && nums[s]== nums[s+1]){
        //                 s++;
        //             }
        //             e--, 
        //             s++;
        //         }
        //     }            
        // }
        
        //using hashmap
        unordered_map<int, int> mp;
        for( int i =0; i<nums.size(); i++){
            mp[nums[i]] = i;
        }
        for(int i=0; i<n; i++){
            if( nums[i]>0) break;
            int target = -nums[i];
            for(int j=i+1; j<nums.size(); ++j){
                //checking if the third element exist and its last occurence > j, if yes then we got our triplet
                if( mp.count( target- nums[j]) && mp[target- nums[j]]>j ){ 
                    
                    ans.push_back({nums[i], nums[j], nums[mp[target - nums[j]]]});
                }
                //updating j to its last occuring positions
                j = mp[nums[j]];
            }
            //updating the first element postion to its last occuring position
            i = mp[nums[i]];
        }
        return ans;
    }
};