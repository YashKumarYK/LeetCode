// Dijkstra using adjacent list
// Use a class PriorityQueue with Container
// (ref: https://stackoverflow.com/questions/1185252/is-there-a-way-to-access-the-underlying-container-of-stl-container-adaptors)
//
#pragma GCC optimize("O3")
using int2 = pair<int, int>;
class PriorityQueueContainer : public priority_queue<int2, vector<int2>, greater<int2>> 
{
public:
    PriorityQueueContainer() = default;
    static const vector<int2>& container(const PriorityQueueContainer& pq) 
    {
        return pq.c;
    }
};

class Graph {
    using int2 = pair<int, int>;
    vector<PriorityQueueContainer> adj;
    int n;

public:
    Graph(int n, vector<vector<int>>& edges) : n(n) {
        adj.resize(n);
        #pragma unroll
        for(auto& edge: edges) {
            adj[edge[0]].emplace(edge[2], edge[1]);
        }
    }

    void addEdge(vector<int> edge) {
        adj[edge[0]].emplace(edge[2], edge[1]);
    }

    int shortestPath(int node1, int node2) {
        PriorityQueueContainer pq; // Min-heap
        vector<int> dist(n, INT_MAX);
        dist[node1] = 0;
        pq.emplace(0, node1);

        #pragma unroll
        while (!pq.empty()) {
            auto [d, i] = pq.top();
            pq.pop();

            if (i == node2) return d;
            if (d > dist[i]) continue;

            int d2;
            // Iterate over the underlying container of the priority queue
            const auto& container = PriorityQueueContainer::container(adj[i]);
            #pragma unroll
            for (const auto& [w, j] : container) {
                d2 = d + w;
                if (d2 < dist[j]) {
                    dist[j] = d2;
                    pq.emplace(d2, j);
                }
            }
        }

        return -1;
    }
};