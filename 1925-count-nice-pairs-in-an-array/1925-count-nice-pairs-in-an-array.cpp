class Solution {
public:
    int rev(int num){
        int ans = 0;
        while(num!=0){
            ans = ans*10 + num%10;
            num = num/10;
        }
        return ans;
    }
    int m = 1e9+7;
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, long long> mp;
        int count=0;
        for(int i=0;i<nums.size(); i++){
            int revnum = rev(nums[i]);
            if(mp.count(nums[i]-revnum)){
                mp[nums[i]-revnum]++;
                count= (count%m +  mp[nums[i]-revnum]%m-1)%m;
            }
            else{
                mp[nums[i]-revnum]++;
            }
        }
        return count%m;
    }
};