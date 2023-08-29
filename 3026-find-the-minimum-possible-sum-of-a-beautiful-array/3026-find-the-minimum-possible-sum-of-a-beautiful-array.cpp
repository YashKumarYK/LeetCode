class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        if(n==1) return 1;
        long long sum =0;
        unordered_map<int,int> mp;
        int i=1;
        while(n){
            if(mp.count(target-i)){
                i++;
                continue;
            }
            sum+= i;
            mp[i]++;
            n--;
            i++;
        }
        return sum;
    }
};