// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	
	    void solve( string s, int ind, multiset<string> &ans, string a){
	        if( ind == s.size()){
	            if (a.size()!=0)
	                ans.insert(a);
	                return;
	        }
	        
	        
	        a.push_back(s[ind]);
	        solve( s,ind+1, ans, a);
	        
	        a.pop_back();
	        
	        solve(s, ind+1, ans, a);
	    }
		vector<string> AllPossibleStrings(string s){
		    
		    int n =s.size();
		    string a;
		    vector<string> ans1;
		    multiset<string> ans;
		    solve( s, 0, ans, a);
		    for( auto i: ans){
		        ans1.push_back(i);
		    }
		    return ans1;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends