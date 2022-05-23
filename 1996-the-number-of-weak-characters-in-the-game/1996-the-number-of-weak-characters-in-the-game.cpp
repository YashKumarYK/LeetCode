static bool compare(vector<int> &a, vector<int> &b){
    if( a[0]== b[0]) return a[1]>b[1];
    else return a[0]<b[0];
}

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort( properties.begin(), properties.end(), compare);
        int count =0;
        
        for(int i=0; i< properties.size(); i++ ){
            for( int j=0; j<properties[0].size(); j++){
                cout<< properties[i][j];
            }
        }
        int maxDefence = INT_MIN;
        int n = properties.size();
        for( int i = n-1; i>=0; i--){
            if( properties[i][1] < maxDefence){
                count++;
            }
            
            maxDefence = max(maxDefence, properties[i][1]);
            
        }
        return count;
    }
};