class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ans(n, 0);
        ans[0] =1;
        int p2=0;
        int p3=0;
        int p5=0;
       for(int i=1;i<n;++i){
            int el = min({ans[p2]*2, ans[p3]*3, ans[p5]*5});
            ans[i] =el;
            if( ans[p2]*2==el) p2++;
            if( ans[p3]*3==el) p3++;
            if( ans[p5]*5==el) p5++;
        }
        return ans[n-1];
    }
};