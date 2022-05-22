class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> arr = rocks;
        for( int i=0; i<rocks.size(); i++){
            arr[i] = capacity[i]- rocks[i] ;
        }
        sort( arr.begin(), arr.end());
        
        int count=0;
        for( int i=0; i<rocks.size(); i++){
            if( arr[i]<= additionalRocks)
            {
                additionalRocks-= arr[i];
                count++;
            }
            else
                break;   
        }    
        return count;
        
        
    }
};