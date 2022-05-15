class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long> v;
        if( num%3 !=0 ) return v;
        long long n = num/3;
        v.push_back(n-1);
        v.push_back(n);
        v.push_back(n+1);
        return v;
    }
};