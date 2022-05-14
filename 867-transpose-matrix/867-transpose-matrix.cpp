class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int R = matrix.size();
        int C = matrix[0].size();
        vector<vector<int>> v( C, vector<int> (R));
        for(int i =0; i< matrix.size(); i++){
            for( int j =0; j<matrix[0].size(); j++){
                v[j][i]= matrix[i][j];
            }
        }
        return v;
    }
};