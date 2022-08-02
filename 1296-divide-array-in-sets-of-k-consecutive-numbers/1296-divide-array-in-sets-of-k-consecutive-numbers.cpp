class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(  nums.size()%k != 0) return 0;
        int size = nums.size()/k;
        
        map<int, int> mp;
        for( auto i: nums){
            mp[i]++;
        }
        int count =0;
        while( !mp.empty()){
            // auto it: mp.begin();
            int start = mp.begin()->first;
            for( int i= start; i< start+k; i++){
                if( mp.find(i)== mp.end()){
                    return false;
                }
                mp[i]--;
                count++;
                if( mp[i]==0) mp.erase(i);
            }
        }
        return true;
    }
};