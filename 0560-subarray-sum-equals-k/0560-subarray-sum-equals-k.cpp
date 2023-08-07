class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // sliding winodw can't be used because of the negativee element
        // suppose there is a consecutive subarray A,B  then sliiding  window only counts these two,it wont count the subarray formed by A+B
        int n = nums.size();
        // vector<int> sumA(n+1, 0);
        int count = 0;
        // sumA[0] =  0;
        // for(int i=1; i<=n; i++){
        //     sumA[i] =  sumA[i-1]+ nums[i-1];
        // }
        // for(int i=0; i<=n; i++){
        //     for(int j=i+1; j<=n;j++){
        //         if(sumA[j]-sumA[i]==k){
        //             count++;
        //         }
        //     }
        // }
        // return count;
        unordered_map<long long, int> mp;
        int sum =0;
        mp[0]++;
        // int count = 0;
        for(int i=0;i<n; i++){
            sum += nums[i];

            if(mp.find(sum-k)!=mp.end()){
                count+= mp[sum-k];
            }
            mp[sum]++;

        }
        return count;
    }
};
