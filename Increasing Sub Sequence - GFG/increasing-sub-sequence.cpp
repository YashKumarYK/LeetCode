//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int maxLength(string S)
    {
        vector<char> temp;
        temp.push_back(S[0]);
        for( int i=1; i<S.size(); i++){
            if(S[i]>temp.back()){
                temp.push_back(S[i]);
            }else{
                int ind = lower_bound(temp.begin(), temp.end(),S[i]) - temp.begin();
                temp[ind]= S[i];
            }
        }
        return temp.size();
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout << ob.maxLength(S) << endl;
    }
    return 0; 
}
// } Driver Code Ends