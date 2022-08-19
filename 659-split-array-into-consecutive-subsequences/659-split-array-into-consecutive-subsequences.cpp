class Solution {
public:
    bool isPossible(vector<int>& nums) {                
        unordered_map<int, int> map;
        
        for(auto num : nums) {
            map[num]++; 
        }
        for(auto& kv:map) {
            int x=kv.first;            
            int l=min(check(map,x-2), check(map,x-1));
            int r=min(check(map,x+2), check(map,x+1));
            int m=min(check(map,x-1)-l, check(map,x+1)-r); 
            
            if(kv.second > (l+r+m))                        
                return false;                        
        }        
        return true;
    }
    int check(unordered_map<int,int>& m, int k) {
        return m.find(k)==m.end()?0:m[k];
    }
};