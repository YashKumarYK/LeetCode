class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev = {1};
        if( rowIndex==0) return prev;
        vector<int> curr(rowIndex+1);
        for(int i=0; i<rowIndex+1; ++i)
        {
            for( int j=0; j<=i; ++j)
            {
                if ( j==0 || j==i)
                {
                    curr[j]= 1;
                    continue;
                }
                else curr[j] = prev[j]+prev[j-1];
            }
            prev = curr;
        }
        return curr;
    }
};