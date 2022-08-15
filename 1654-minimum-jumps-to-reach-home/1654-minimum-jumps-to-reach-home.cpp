class Solution {
public:
    int minimumJumps(vector<int>& forb, int a, int b, int x) {
        // unordered_set<int> s(forb.begin(), forb.end());
        unordered_map<int,int> mp;
        for( int i=0;i<forb.size(); i++) mp[forb[i]]++;
        
        queue<pair<int,bool>> q;
        q.push({0,1});
        // bool can = true;
        // s.insert(0);
        int count =0;
        while(!q.empty()){
            int size = q.size();
            for( int i=0; i<size; i++){
                int front = q.front().first;
                bool can = q.front().second;
                
                q.pop();
                
                if( front==x) return count;
                
                if(mp.count(front)) continue;
                mp[front]++;
                
                int forw = front+a;
                int back = front-b;
                
                if( can && back>=0 ){
                    q.push({back, 0});
                }
                if( front<=2000+b ){
                    q.push({forw, 1});
                }
            }
            count++;
        }
        return -1;
    }
};