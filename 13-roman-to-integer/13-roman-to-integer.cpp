class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        int sum =0;
        map<char, int> mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']= 100;
        mp['D']= 500;
        mp['M']= 1000;
        
        for(int i = n-1; i>=0; i--){
            char ch = s[i];
            if( i!=n-1 && mp[ch] < mp[s[i+1]]){
                sum = sum-mp[ch];
            }
            else 
                sum = sum+ mp[ch];
        }
        return sum;
    }
};