class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> adj[n];
        int m = 1e9+7;

        for(auto i:roads){
            int u = i[0];
            int v = i[1];
            int w = i[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<long long> dist(n, LONG_MAX);  // for distance
        vector<long long> ways(n, 0); //for the ways;
        dist[0] = 0;
        ways[0] = 1;

        priority_queue<pair<long long,int>, vector<pair<long long,int>> ,greater<pair<long long,int>>> pq;
        pq.push({0,0});
        while(!pq.empty()){
            int node = pq.top().second;
            long long distance = pq.top().first;
            pq.pop();

            for( auto i: adj[node]){
                int next = i.first;
                long long d = i.second;
                if(distance+d < dist[next]){
                    dist[next] = distance+d;
                    ways[next] = ways[node];  
                    pq.push({dist[next], next});
                }
                else if(distance+d == dist[next]){
                    ways[next] = (ways[next]%m + ways[node]%m)%m;
                }
            }
        }
        return ways[n-1]%m;
    }
};