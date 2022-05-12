class Solution {
public:
    void solve(string digits, vector<string> &ans, int index, string mapping[], string s){
        if( index >= digits.length()){
            ans.push_back(s);
            return;
        }
        
        int number = digits[index]- '0';
        string value = mapping[number];
        
        for(int i= 0; i< value.length(); i++){
            s.push_back(value[i]);
            solve(digits, ans, index+1, mapping, s);
            
            //back_tracking
            s.pop_back();
        
        }
    }
    vector<string> letterCombinations(string digits) {
        
        vector<string> ans;
        if(digits.length()==0) return ans;
        
        string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int index=0;
        
        string s="";
        solve( digits, ans, index, mapping, s);
        return ans;
    }
};