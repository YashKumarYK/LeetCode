class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        int n = a.size();
        vector<int> ans;
        stack<int> s;
        s.push(a[n-1]);
        for( int i=n-2; i>=0; --i){
            if(!s.empty() && (s.top()<0 && a[i]>0)){
                int front = a[i];
                bool flag = true;
                while( !s.empty() &&(s.top()<0 && front >0)){
                    if( abs(front) == abs(s.top())){
                        flag = false;
                        s.pop();
                        break;
                    }
                    front = abs(front)>abs(s.top())? front: s.top();
                    s.pop();
                }
                if( flag)
                    s.push(front);
            }
            else{
                s.push(a[i]);
            }
        }
        while( !s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};