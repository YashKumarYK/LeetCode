class Solution {
public:
    static bool comp( string &a, string &b){
        return  (a+b)>(b+a);
    }
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for( int i=0; i<nums.size(); ++i){
            string s  = to_string(nums[i]);
            v.push_back(s);
        } 
        sort( v.begin(), v.end(), comp);
        string s="";
        for( auto num: v){
            s+= num;
        }
        if( s[0]=='0' && s.size()>1) return "0";
        return s;
    }
};