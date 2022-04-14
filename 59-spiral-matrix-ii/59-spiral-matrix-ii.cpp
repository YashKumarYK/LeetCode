class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
//         vector<int> ans;
//         vector<vector<int>> matrix;
//         int startingRow= 0;
//         int endingRow= n-1;
//         int startingCol = 0;
//         int endingCol = n-1;
        
//         int count=1;
//         int total = n*n;
//         while(count<=total){
//             //for starting row;
//             for(int index = startingCol; index<=endingCol; index++){
//                 ans.push_back(count++);
//             }
//             startingRow++;
            
//             //for ending column'
//             for(int index= startingRow; index<=endingRow; index++){
//                 ans.push_back(count++);
//             }
//             endingCol--;
            
//             for(int index = endingCol; index>= startingCol; index--){
//                 ans.push_back(count++);
//             }
//             endingRow--;
            
//             for(int index= endingRow; index>= startingRow; index--){
//                 ans.push_back(count++);
//             }
//             startingCol++;
//         }
        // int k=0;
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<n; j++){
        //         matrix[i][j]= ans[k++];
        //     }
        // }
        // return matrix;
        // vector<int> ans;
        
        int count=0;
        int total = n*n;
        
        vector<vector<int>> matrix (n , vector<int> (n, 0));
        
        int startingCol = 0;
        int startingRow= 0;
        int endingRow = n-1;
        int endingCol = n-1;
        
        while(count<total){
            //starting row
            for(int index = startingCol; count<total&& index<=endingCol; index++){
                matrix[startingRow][index]= count+1;
                count++;
            }
            startingRow++;
            
            //end column
            for(int index= startingRow;count<total && index<=endingRow; index++){
                matrix[index][endingCol]= count+1;
                count++;
            }
            endingCol--;
            
            //ending row;
            for(int index = endingCol; count<total && index>=startingCol; index --){
                matrix[endingRow][index]= count+1;
                count++;
            }
            endingRow--;
            
            //starting Column
            for(int index = endingRow; count<total && index>=startingRow; index--){
                matrix[index][startingCol]= count+1;
                count++;
            }
            startingCol++;
        }
        return matrix;
        // return ans;
    }
};