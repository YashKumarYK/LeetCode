class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        if(n==1) return 1;
        long long sum =0;
        int half = target/2;
        int cnt =0;
        for(int i=1;i<=half; i++){
            cnt++;
            sum += i;
            if(cnt == n) return sum;
        }
        
        while(cnt<n){
            sum += target++;
            cnt++;
        }
        return sum;
    }
};