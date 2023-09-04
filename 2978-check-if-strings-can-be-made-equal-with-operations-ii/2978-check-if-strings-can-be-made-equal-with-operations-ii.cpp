class Solution {
public:
    bool checkStrings(string s1, string s2) {
        if(s1==s2) return true;
        int n = s2.size();
        for(int i=0;i<n;i++){
            if(s1[i]==s2[i]) continue;
            bool possible = false;
            for(int j = i; j<n; j= j+2){
                if(s1[i]==s2[j]){
                    swap(s2[i], s2[j]);
                    possible = true;
                    break;
                }
            }
            if(!possible) return false;
        }
        return true;
    }
   
};