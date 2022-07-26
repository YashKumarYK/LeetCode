class Solution {
public:
    // unordered_map<pair<int, int>, vector<int>> mp;
    vector<int> solve( string s, int i, int j ){
        
        // if( mp.find({i,j})!= mp.end()) return mp[{i,j}];
        
        vector<int> ans;
        for( int k = i; k< j; ++k){
            if( s[k]=='*'||s[k]=='-'||s[k]=='+'){
                vector<int> l = solve(s, i, k-1);
                vector<int> r = solve( s, k+1, j);

                for( auto x: l){
                    for( auto y: r){
                        if( s[k]=='-') ans.push_back(x-y);

                        else if( s[k]=='+') ans.push_back(x+y);

                        else if( s[k]=='*') ans.push_back( x*y);

                    }
                }
            }
        }
        
        if( ans.size()==0) ans.push_back( stoi( s.substr(i, j-i+1)));
        return ans; 
    }
    
    vector<int> diffWaysToCompute(string exp) {
        int s = 0;
        int n = exp.size();
        int e = n-1;
        
        return solve(exp, s, e);
    }
};