class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        if(s1==s2) return true;
        int i= 0;
        int j =0;
        while(i<4){
            if(s1==s2) return true;
            j = i;
            if(s1[i]==s2[j]){
                i++;
                continue;
            }
            if(s1[i]!= s2[j]){
                if(i<2 && s1[i+2]==s2[j]){
                    swap(s1[i+2], s1[i]);
                    i++;
                    continue;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};