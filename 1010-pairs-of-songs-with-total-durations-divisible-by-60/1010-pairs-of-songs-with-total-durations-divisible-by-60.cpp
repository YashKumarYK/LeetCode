class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        for(int i =0; i<time.size(); i++){
            time[i]= time[i]%60;
        }
        unordered_map<int, int> mp;
        int count =0;
        for(auto x : time){
            if( x ==0)
                count += mp[0];
            else{
                count += mp[60-x];
            }
            mp[x]++;
        }
        return count;
    }
};