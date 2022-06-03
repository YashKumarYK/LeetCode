// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findMaxSum(int N, int M, vector<vector<int>> Mat) {
        int r = Mat.size();
        int c = Mat[0].size();
        int maxi = INT_MIN;
        if( r<3 ||c<3) return -1;
        for( int i= 1; i<r-1; i++){
            for( int j=1; j<c-1; j++){
                int sum = Mat[i][j]+ Mat[i-1][j]+ Mat[i+1][j]+ Mat[i-1][j-1]+ Mat[i-1][j+1]+ Mat[i+1][j-1]+ Mat[i+1][j+1];
                maxi = max( sum, maxi);
            }
        }
        return maxi;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, i, j;
        cin >> N >> M;
        vector<vector<int>> Mat(N, vector<int>(M));
        for (i = 0; i < N; i++)
            for (j = 0; j < M; j++) cin >> Mat[i][j];
        Solution ob;
        cout << ob.findMaxSum(N, M, Mat) << "\n";
    }
}  // } Driver Code Ends