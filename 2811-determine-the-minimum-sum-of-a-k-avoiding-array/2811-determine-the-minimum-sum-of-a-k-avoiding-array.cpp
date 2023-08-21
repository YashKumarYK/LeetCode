class Solution {
public:
    int minimumSum(int n, int k) {
        int i =1;
        unordered_map<int,int> mp;
        int sum =0;
        while(n!=0){
            if(mp.count(k-i)){
                i++;
                continue;
            }
            sum+= i;
            mp[i]++;
            i++;
            n--;  
        }
        return sum;
    }
};