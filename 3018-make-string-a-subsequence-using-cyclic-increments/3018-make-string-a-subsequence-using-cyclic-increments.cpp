class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        if(m>n) return false;
        char ch = str1[n-1];
        char ch2 = (((ch-'a')+1)%26)+'a';
        int i=0;int j=0;
        while(i<n && j<m){
            char ch = str1[i];
            char ch2 = (((ch-'a')+1)%26)+'a';
            if(str1[i]==str2[j] || str2[j]==ch2){
                j++;
                
            }
            i++;
        }
        if(j==m) return true;
        return false;

    }
};