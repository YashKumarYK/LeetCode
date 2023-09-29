bool comparator( vector<int> &a, vector<int> &b){
        if( a[0]== b[0]) return a[1]>b[1];
        return a[0]<b[0];
}

class Solution {
public:
    
    int maxEnvelopes(vector<vector<int>>& env) {
        sort(env.begin(), env.end(), comparator);
        vector<int> temp;
        temp.push_back(env[0][1]);
        for(int i=1; i<env.size(); i++){
            if(temp.back()< env[i][1]){
                temp.push_back(env[i][1]);
            }else{
                int ind = lower_bound(temp.begin(), temp.end(),env[i][1]) - temp.begin();
                temp[ind] = env[i][1];
            }
        }
        return temp.size();
    }
};