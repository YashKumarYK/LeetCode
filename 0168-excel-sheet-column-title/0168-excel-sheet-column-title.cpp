class Solution {
public:
    string convertToTitle(int colNum) {
        string ans ="";
        while( colNum!=0 ){
            colNum--;
            int rem = colNum%26;
            char ch = (rem)+'A';
            ans.push_back(ch);
            // cout<<rem<<" ";
            colNum/=26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};