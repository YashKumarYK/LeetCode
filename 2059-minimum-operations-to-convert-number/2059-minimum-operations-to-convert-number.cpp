class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        int n = nums.size();
        queue<int> q;
        unordered_map<int, int> s;
        
        q.push(start);
        int count =0;
        while( !q.empty()){
            int size = q.size();
            for( int i=0; i<size; ++i){
                int front = q.front();
                q.pop();
                
                if( front == goal) return count;
                if( front<0 || front >1000 || s.count(front)){
                    continue;
                }
                // s.insert(front);
                s[front]++;
                
                for( int i=0; i<n; ++i){
                    q.push( front+ nums[i]);
                    q.push( front-nums[i]);
                    q.push( front^nums[i]);
                }
            }
            count++;
        }
        return -1;
    }
};