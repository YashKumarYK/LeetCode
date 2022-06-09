class Solution {
public:
    bool solve( vector<int> &arr, int s, int n, vector<int> &visited){
        if( s>=n || s<0) return false;
        if( arr[s]==0) return true;
        if(visited[s] ==1) return false;
        
        visited[s]=1;
        bool right = solve( arr, s+arr[s], n, visited);
        bool left = solve(arr, s-arr[s],n, visited);
        
        return right||left;
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> visited(n,0);
        return solve(arr, start, n, visited);
    }
};