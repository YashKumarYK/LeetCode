class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        unordered_map<char, int> mp;
        for( int i=0; i<tasks.size(); ++i){
            mp[tasks[i]]++;
        }
        vector<int> v;
        for( auto i:mp) v.push_back(i.second);
        sort( v.begin(), v.end(), greater<> ());
        int maxi = v[0];
        
        int count =0;
        int i=0;
        while(i<v.size() && v[i]==maxi){
            ++count;
            ++i;
        }
        
        int len = tasks.size();
        int ans = (maxi-1)*(n+1) + count;
        return max( len, ans);
    }
};