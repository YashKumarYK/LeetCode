class Solution {
public:
    int countHomogenous(string s) {
        int ans =0;
        int i=0;
        int m = 1e9+7;
        while(i<s.size()){
            long long count=1;
            int j=i;
            while(j<s.size()-1 && s[j+1]==s[j]){
                count++;
                j++;
            }
            ans = ans%m + (count*(count+1)/2)%m;
            i = j+1;
        }
        return ans%m;
    }
};

// aaa => a, a, a, aa, aa, aaa
// aa => a,a,aa
// a =>a
// abcd => a, b, c, d, ab, bc, cd, abc, acd, abcd