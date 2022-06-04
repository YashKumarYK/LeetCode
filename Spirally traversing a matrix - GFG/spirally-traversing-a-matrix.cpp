// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        int total = r*c;
        int startrow = 0;
        int endrow= r-1;
        int startcol = 0;
        int endcol = c-1;
        int count=0;
        vector<int> ans;
        while( count<total){
            for(int i= startcol; count<total && i<=endcol; i++){
                ans.push_back( matrix[startrow][i]);
                count++;
            }
            startrow++;
            
            for(int i= startrow; count<total && i<=endrow; i++){
                ans.push_back(matrix[i][endcol]);
                count++;
            }
            endcol--;
            
            for(int i= endcol;count<total && i>=startcol; i--){
                ans.push_back( matrix[endrow][i]);
                count++;
            }
            endrow--;
            
            for(int i= endrow; count<total && i>=startrow; i--){
                ans.push_back(matrix[i][startcol]);
                count++;
            }
            startcol++;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends