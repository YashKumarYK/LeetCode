class Solution {
public:
    
    
    int op(int x, int num, int a){
        if( a== 0){
            x-=num;
        }
        else if( a==1){
            x+=num;
        }
        else{
            x^=num;
        }
        return x;
    }
    int minimumOperations(vector<int>& nums, int start, int goal) {
        int n = nums.size();
        queue<int> q;
        set<int> s;
        
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
                s.insert(front);
                
                for( int i=0; i<n; ++i){
                    for(int j=0; j<3; j++){
                        int x = op(front, nums[i], j);
                        q.push(x);
                    }
                }
            }
            count++;
        }
        return -1;
    }
};