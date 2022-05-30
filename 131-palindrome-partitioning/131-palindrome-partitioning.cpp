class Solution {
public:
    
    bool ispal( string st, int s , int e){
        while( s<=e){
            if( st[e] != st[s]){
                return false;
            }
            s++;
            e--;
        }
        return true;
    }
    void partpali( string s, int index, vector<string> path, vector<vector<string>> &ans){
        if( index == s.length()){
            ans.push_back( path);
            return;
        }
        
        for( int i = index ; i<s.length() ; i++){
            if( ispal(s, index, i)){
                path.push_back( s.substr( index, i- index+1));
                partpali(s, i+1, path, ans);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> path;
        vector<vector<string>> ans;
        partpali( s, 0, path, ans);
        return ans;
    }
};