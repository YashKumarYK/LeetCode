class Solution {
public:
    
    bool possible(int n){
        if(n<10) return false;
        string s  = to_string(n);
        if(s.size()%2) return false;
        int i= 0, j = s.size()-1;
        int lsum =0;
        int rsum =0;
        while(i<j){
            lsum+= (s[i]-'0');
            rsum += (s[j]-'0');
            i++;
            j--;
        }
        return lsum==rsum;
    }
    int countSymmetricIntegers(int low, int high) {
        int cnt =0;
        for(int i=low; i<=high; i++){
            if(possible(i)){
                cout<<i<<" ";
                cnt++;
            }
        }
        return cnt;
    }
};