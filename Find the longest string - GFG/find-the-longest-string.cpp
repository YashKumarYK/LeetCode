//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string longestString(vector<string> &words)
    {
        sort(words.begin(), words.end());
        unordered_map<string,int> mp;
        for( auto ch: words){
            mp[ch]++;
            // cout<<ch<<"->";
        }
        string ans="";
        for(int i= 0; i< words.size(); i++){
            string word = words[i];
            string s="";
            bool flag = true;
            for(int i =0; i<word.size(); i++){
                s+= word[i];
                // cout<<s<<"->";
                if( mp.find(s)==mp.end()){
                    flag = false;
                    break;
                }
            }
            // cout<<endl;
            if(flag){
                if(ans.size()<s.size())
                    ans = s;
            } 
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends