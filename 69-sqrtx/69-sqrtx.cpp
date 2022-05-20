class Solution {
public:
    int mySqrt(int x) {
        int start=0;
        int end = x;
        long long mid = start + (end - start)/2;
        long long ans=-1;
        while(start<=end){
            long long sqr= mid*mid;
            if (sqr ==x) return mid;
            if (sqr<x){
                ans = mid;
                start= mid+1;
            }
            else{
                end = mid-1;
            }
            mid = start+(end-start)/2;
        }
        return ans;
    }
};