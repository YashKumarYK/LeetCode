class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {        
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
        
    }
};