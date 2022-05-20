class Solution {
public:
    bool judgeSquareSum(int c) {
        for( long i =0; i*i<=c; i++){
            long s=0;
            long  e= c-(i*i);
            long long mid = s+ (e-s)/2;
            while(s<=e){
                if( mid*mid== c-(i*i)) return true;
                else if( mid*mid >c-(i*i)) e= mid-1;
                else s= mid+1;
                
                mid= s+(e-s)/2;
            }
        }
        return false;
    }
};