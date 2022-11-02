class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_map<string, int> mp;
        for(int i=0;i< bank.size(); i++){
            mp[bank[i]]++;
        }
        char v[4]={'A','C','G','T'};
        queue<string> q;
        q.push(start);
        int c =0;
        while(!q.empty()){
            int size= q.size();
            for(int i=0; i<size; i++){
                string s = q.front();
                q.pop();
                if( s == end) return c;
                
                if( mp.find(s)!= mp.end()) mp.erase(s);
                
                for(int i=0; i<8; i++){
                    for(int j=0; j<4; j++){
                        string s1 =s;
                        s1[i]= v[j];
                        if(mp.find(s1)!= mp.end()){
                
                            q.push(s1);         
                        }
                    }
                }
            }
            c++;
        }
        return -1;
    }
};