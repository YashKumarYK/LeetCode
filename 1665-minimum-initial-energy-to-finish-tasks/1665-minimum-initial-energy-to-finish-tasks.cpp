class comparator{
public:
    bool operator()(vector<int> &a, vector<int> &b){
        return a[1]-a[0]> b[1]-b[0];
    }
};
    
class Solution {
public:
    
    int minimumEffort(vector<vector<int>>& tasks) {
        sort( tasks.begin(), tasks.end(), comparator());
        int temp =0;
        int carry =0;
        for( auto i: tasks){
            if( i[1]<=carry){
                carry -= i[0];
            }
            
            else{
                temp+= i[1]- carry;
                carry = i[1]- i[0];
            }
        }
        return temp;
    }
};