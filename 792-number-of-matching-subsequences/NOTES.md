***Recursion + Memoization***
```
bool match( string &s, string &t,int m, int n, vector<vector<int>> &dp){
if( n==0) return true;
if( m==0) return false;
if( dp[m][n]!=-1) return dp[m][n];
if( t[n-1]==s[m-1]){
return dp[m][n] = match( s, t, m-1, n-1, dp);
}
else{
return dp[m][n]=match( s, t, m-1, n, dp);
}
}
int numMatchingSubseq(string s, vector<string>& words) {
int count =0;
unordered_map<string, int> mp;
for(int i=0; i<words.size(); i++){
mp[words[i]]++;
}
for( auto word: mp){
string t = word.first;
vector<vector<int>> dp( s.size()+1, vector<int> (t.size()+1, -1));
if( match(s, t, s.size(), t.size(), dp)) count++;
}
return count;
```