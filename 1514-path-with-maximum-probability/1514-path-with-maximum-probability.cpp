class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int, double>> adj[n];
        for(int i=0; i<edges.size(); i++){
            int u= edges[i][0];
            int v= edges[i][1];
            double w = succProb[i];
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<double> dist(n, 0);
        priority_queue<pair<double, int>> pq;
        
        dist[start]= 1;
        pq.push({1, start});
        
        while(!pq.empty()){
            int node = pq.top().second;
            double prob = pq.top().first;
            pq.pop();
            
            vector<pair<int, double>> :: iterator it;
            for( auto it: adj[node]){
                int next = it.first;
                double nextprob = it.second;
                
                if( dist[node]* nextprob > dist[next]){
                    dist[next] = dist[node]* nextprob;
                    pq.push({dist[next], next});
                }
            }
        }
        return dist[end];
    }
};