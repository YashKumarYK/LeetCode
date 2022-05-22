class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int n= strs[0].size();
        bool flag = true;
        for( int i=0; i<n; i++){
            int ch = strs[0][i];
            for(int j= 0; j<strs.size(); j++){
                if( strs[j][i] != ch){
                    flag = false;
                    break;
                }
            }
            if (flag ==true)
                ans.push_back(ch);
            else break;
        }
        return ans;
    }
};