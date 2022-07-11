class Solution {
public:
    int totalFruit(vector<int>& f) {
        int i=0;
        int j =0;
        unordered_map<int, int> mp;
        int len = INT_MIN;
        while( j<f.size()){
            mp[f[j]]++;
            
            if( mp.size()<=2){
                len = max( len, j-i+1);
            }
            
            if( mp.size()>2){
                while( mp.size()> 2){
                    mp[f[i]]--;
                    if( mp[f[i]]==0){
                        mp.erase(f[i]);
                    }
                    i++;
                }
            }
            j++;
        }
        return len==INT_MIN? 1:len;
    }
};