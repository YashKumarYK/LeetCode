// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool isThisBipartite( int node, vector<int> &color, vector<int> adj[]){
        queue<int> q;
        q.push(node);
        color[node]=1;
        
        while( !q.empty()){
            int front = q.front();
            q.pop();
            
            //traverse to the neighbour
            for( auto neigbour : adj[front]){
                if( color[neigbour] == -1){
                    q.push(neigbour);
                    color[neigbour] = 1- color[front];
                }
                else if( color[ neigbour]== color[front]){
                    return false;
                }
            }
        }
        return true;
    }
    
    // bool isThisBipartite( int node, vector<int> color, vector<int> adj[]){
    //     color[ node] =1;
        
    //     for( auto i: adj[node]){
    //         if( color[i] == -1){
    //             return isThisBipartite(i , color, adj){
    //         }
    //     }
    // }
    
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> color(V, -1);
	    for( int i = 0 ; i<V; i++){
	        if( color[i] == -1){
	            if(!isThisBipartite( i, color, adj))
	                return false;
    	    }
	    }
	    return true;
	}
	

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends