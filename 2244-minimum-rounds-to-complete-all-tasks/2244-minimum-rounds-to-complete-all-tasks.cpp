class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> mp;
        for( auto i: tasks){
            mp[i]++;
        }
        int round =0;
        for( auto i:mp){
            if( i.second==1) return -1;
            else{
                //if the remainder is zero
                if( i.second%3 ==0){
                    round+= i.second/3;
                }
                //if the remainder is 1
                else if( i.second%3 ==1){
                    round+= i.second/3 +1;
                }
                else{
                    //if the remainder is 2
                    round += i.second/3 +1;
                }
            }
        }
        return round;
    }
};