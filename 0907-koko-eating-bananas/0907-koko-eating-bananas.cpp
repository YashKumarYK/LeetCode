class Solution {
public:

    bool possible( vector<int> piles, int hours, int k){
        int th = 0;
        for( auto b: piles){
            th+= b/k;
            if(b%k!=0){
                th+= 1;
            }
        }
        return th<=hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int start = 1;
        int end = INT_MAX;
        int ans = -1;
        while(start<= end){
            int mid = start+(end-start)/2;
            if(possible(piles, h,  mid)){
                ans = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return ans;
    }
};
