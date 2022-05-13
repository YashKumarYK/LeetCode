class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map< int , int> m;
        for( int i=0; i<arr.size(); i++){
            if( m.find(arr[i]) !=m.end()){
                m[arr[i]]++;
            }
            else m[arr[i]] = 1;
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