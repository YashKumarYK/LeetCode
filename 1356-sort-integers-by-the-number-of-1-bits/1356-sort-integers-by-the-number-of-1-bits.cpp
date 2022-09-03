class Solution {
public:
    
    static bool comparator(int &a, int &b){
        int n1 = __builtin_popcount(a);
        int n2 = __builtin_popcount(b);
        if( n1 == n2){
            return a<b;
        }
        return n1<n2;
    }
    vector<int> sortByBits(vector<int>& arr) {
        int n =arr.size();
        sort( arr.begin(), arr.end(), comparator);
        return arr;
    }
};