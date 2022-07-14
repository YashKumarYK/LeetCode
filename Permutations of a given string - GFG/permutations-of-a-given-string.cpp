// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	
	    void solve( string &s, set<string> &ans, int ind){
	        if( ind == s.size()){
	            ans.insert(s);
	            return;
	        }
	        for(int i=ind; i<s.size(); i++){
	            swap( s[ind], s[i]);
	            solve(s, ans, ind+1);
	            swap(s[ind], s[i]);
	        }
	    }
		vector<string>find_permutation(string s)
		{
		    int n = s.size();
		    set<string> s1;
		    vector<string> ans;
		    solve( s, s1, 0);
		    for(auto i: s1){
		        ans.push_back(i);
		    }
		    return ans;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends