// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        vector<int> ans;
        int arr1[100001] = {0};
        for(int i=0; i<n; i++){
            arr1[arr[i]]++;
        }
        for( int i=0; i<=100000; i++){
            if( arr1[i]>1) ans.push_back(i);
        }
        if( ans.size()==0) return {-1};
        return ans;
    }
};


// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}
  // } Driver Code EndsFind duplicates in an arra