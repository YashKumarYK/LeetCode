class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int ind = lower_bound( arr.begin(), arr.end(), x)- arr.begin();
        cout<<ind<<" ";
        priority_queue<int> maxh;
        priority_queue<int, vector<int>, greater<int>> minh;
        vector<int> ans;
        int n = arr.size();
        for( int i=ind-1; i>=0; i--){
            maxh.push(arr[i]);
        }
        for( int i= ind; i<n; ++i){
            minh.push(arr[i]);
        }
        
        while( k>0 && !maxh.empty() && !minh.empty()){
            int t1 = maxh.top();
            int t2 = minh.top();
            if( abs(t1-x)> abs(t2-x)){
                ans.push_back(t2);
                minh.pop();
            }
            else if(abs(t1-x) < abs(t2-x)){
                ans.push_back(t1);
                maxh.pop();
            }
            else{
                ans.push_back( t2>t1?t1:t2);
                t1<t2? maxh.pop():minh.pop();
            }
            k--;
        }
        if(k>0){
            if( maxh.empty()){
                while( k>0 && !minh.empty()){
                    k--;
                    ans.push_back(minh.top());
                    minh.pop();
                }
            }
            else if( minh.empty()){
                while(k>0 && !maxh.empty()){
                    k--;
                    ans.push_back(maxh.top());
                    maxh.pop();
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};