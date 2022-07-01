bool comparator(vector<int> &a, vector<int> &b){
    if( a[1]== b[1]) return a[0]>b[0];
    return a[1]>b[1];
}
class Solution {
public:
    
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort( boxTypes.begin(), boxTypes.end(), comparator);
        
        int ans=0;
        for( auto i: boxTypes){
            if(truckSize> i[0]){
                ans = ans+ i[1]*i[0];
                truckSize -= i[0];
            }
            else{
                ans = ans+ truckSize*i[1];
                break;
            }
        }
        return ans;
    }
};