class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        if(n==1) return false;
        string newStr = s+s;
        newStr.erase(newStr.begin());
        newStr.pop_back();
        for(int i=0;i<=newStr.size()-n; i++){
            if(newStr.substr(i, n)== s) return true;
        } 
        return false;
    }
};