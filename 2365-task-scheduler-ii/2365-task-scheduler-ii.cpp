class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<long long,long long> mp;
        vector<long long> v(tasks.size());
        v[0]=1;
        mp[tasks[0]]= 1;
        // cout<<v[0]<<" ";
        for( int i=1; i<tasks.size(); i++){
            v[i] = v[i-1] +1;
            if( mp.find(tasks[i])==mp.end()){
                mp[tasks[i]]= v[i];
                
            }
            else {
                if(v[i]-mp[tasks[i]]<=space)
                    v[i]= mp[tasks[i]]+ space+1;
                mp[tasks[i]] = v[i];
            }
            // cout<<tasks[i] << "->" << mp[tasks[i]]<<" "<<endl;
        }

        return v[v.size()-1];
    }
};