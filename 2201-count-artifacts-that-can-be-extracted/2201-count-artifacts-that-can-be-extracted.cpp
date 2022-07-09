class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        int count =0;
        vector<vector<int>> grid( n, vector<int> (n, 1));
        for(auto i: dig){
            grid[i[0]][i[1]] =0;
        }
        
        for(auto i: artifacts){
            int sum =0;
            for(int j= i[0]; j<=i[2]; j++){
                for( int k=i[1]; k<=i[3]; k++){
                    sum += sum+grid[j][k];
                }
            }
            if( sum ==0) count++;
        }
        return count;
    }
};