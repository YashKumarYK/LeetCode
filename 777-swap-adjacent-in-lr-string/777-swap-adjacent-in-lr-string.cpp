class Solution {
public:
    bool canTransform(string start, string end) {
        int n = start.size();
        string s1, s2;
        vector<int> v1, v2;
        for( int i=0; i<n; i++){        
            if(start[i]!='X') {
                s1+= start[i];
                v1.push_back(i);
            }
            
            if(end[i]!='X') {
                s2+= end[i];
                v2.push_back(i);
            }
        }
        if(s1!=s2) return false;
        
        for(int i=0; i<v1.size(); ++i){
            if((start[v1[i]]=='R' && v1[i]>v2[i]) || (start[v1[i]]=='L' && v1[i]<v2[i])){
                return false;
            }
        }
        return true;
    }
};