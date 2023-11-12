class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& r, int source, int target) {
        if(source==target) return 0;
        map<int,vector<int>> stopToRoute;
        for(int i=0;i<r.size();i++){
            for(auto stops: r[i]){
                stopToRoute[stops].push_back(i);
            }
        }

        vector<int> vis(r.size(), 0);
        queue<int> q;
        q.push(source);
        int bus = 0;

        while(!q.empty()){
            int s= q.size();
            for(int i=0; i<s; i++){
                int stop = q.front();
                q.pop();
                if(stop== target){
                    return bus;
                }
                for(auto i: stopToRoute[stop]){
                    if(vis[i]==0){
                        vis[i]=1;
                        for(int nextStop: r[i]){
                            q.push(nextStop);
                        }
                    }
                }
            }
            bus++;
        }
        return -1;
    }
};