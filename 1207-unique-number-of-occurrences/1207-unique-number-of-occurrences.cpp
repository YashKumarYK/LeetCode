class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map< int , int> m;
        for( int i=0; i<arr.size(); i++){
            m[arr[i]]++;
        }
        set<int> v;
        for( auto i: m){
            v.insert( i.second);
        }
        int sum =0;
        for( auto i:v){
            sum+= i;
        }
        if (sum == arr.size()) return true;
        return false;
    }
};