class Solution {
public:
    int maxConsecutiveAnswers(string a, int k) {
        int i=0, j=0, n= a.size();
        int len = 0;
        int Tcnt = 0, Fcnt =0;
        while(j<n){
            if(a[j]=='T') Tcnt++;
            else Fcnt++;
            while( min(Fcnt, Tcnt)>k){
                if(a[i]=='T') Tcnt--;
                else Fcnt--;
                i++;
            }
            len = max(len, Fcnt+ Tcnt);
            j++;
        }
        return len;
    }
};