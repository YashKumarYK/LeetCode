class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int,double>> adj[n];
        for(int i=0;i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double w = succProb[i];
            adj[v].push_back({u, w});
            adj[u].push_back({v, w});
        }

        vector<double> dist(n, 0);
        priority_queue<pair<double,int>> pq;
        dist[start] = 1;
        
        pq.push({1,start});
        while(!pq.empty()){
            double prob = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for( auto i: adj[node]){
                int nextNode = i.first;
                double nxtprob = i.second;
                if(dist[node]*nxtprob>dist[nextNode]){
                    dist[nextNode] = dist[node]*nxtprob;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }
        return dist[end];
    }
};