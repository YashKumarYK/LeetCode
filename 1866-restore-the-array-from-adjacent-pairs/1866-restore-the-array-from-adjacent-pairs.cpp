class Solution {
public:
    void dfs(vector<int> &ans, int start, map<int, vector<int>> &mp, unordered_map<int, bool> &vis){
        ans.push_back(start);
        vis[start] = true;
        for(auto i: mp[start]){
            if(vis.count(i)==false){
                dfs(ans, i, mp, vis);
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& ap) {
        map<int,vector<int>> mp;
        for(auto i: ap){
            mp[i[0]].push_back(i[1]);
            mp[i[1]].push_back(i[0]);
        }

        vector<int> ans;
        int start = -1;
        for(auto i: mp){
            if(i.second.size()==1){
                start = i.first;
                break;
            }
        }
        if(start==-1) return ap[0];
        unordered_map<int,bool> vis;
        dfs(ans, start, mp, vis);
        return ans;

    }
};