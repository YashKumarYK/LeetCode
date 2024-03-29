class Solution {
public:
    int nextGreaterElement(int n) {
        if( n<12) return -1;
        string s = to_string(n);
        next_permutation(s.begin(), s.end());
        
        if( stoll(s)> INT_MAX || stoll(s)<=n) return -1;
        return stoll(s);
    }
};