class Solution {
public:
    int minMoves(vector<int>& nums) {
//         int indmaxi = max_element( nums.begin(), nums.end())- nums.begin();
//         int indmini = min_element( nums.begin(), nums.end())- nums.begin();
//         int steps = 0;
//         int mini = INT_MAX;
//         int maxi = INT_MIN;
//         while( maxi!=mini){
//             steps = nums[indmaxi] - nums[indmini];
            
//             for( int i=0; i<nums.size(); i++){
//                 if( i!= indmaxi){
//                     nums[i]+= steps;
//                 }
//                 if( nums[i]<= mini){
//                     mini = nums[i];
//                     indmini = i;
//                 }
//                 if( nums[i]>= mini){
//                     maxi = nums[i];
//                     indmaxi = i;
//                 }
//             }
//         }
//         cout<<indmaxi<<" "<<indmini;
//         return steps;
        int mini = *min_element( nums.begin(), nums.end());
        int steps =0;
        for(int i=0;i<nums.size();i++) steps += nums[i]-mini;
        return steps;
        
    }
};