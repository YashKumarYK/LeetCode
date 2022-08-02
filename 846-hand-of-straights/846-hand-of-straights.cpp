class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int g) {
        int n = hand.size();
        if( n%g !=0) return false;
        
        map<int, int> mp;
        for( int i=0;i<n;i++) mp[hand[i]]++;
        
        while( !mp.empty()){
            int s= mp.begin()->first;
            for( int i=s;i<s+g; i++){
                if( mp.find(i)==mp.end()){
                    return false;
                }
                
                mp[i]--;
                if( mp[i]==0) mp.erase(i);
            }
        }
        return true;
    }
};