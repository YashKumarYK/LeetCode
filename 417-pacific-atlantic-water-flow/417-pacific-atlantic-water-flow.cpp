class Solution {
public:
    vector<int> c;
    void rec(vector<vector<int>> &h, int i, int j, set<pair<int, int>> &st) {
        
        // int ret = 0;
        st.insert({i,j});
        // cout<<i<<j;
        if(i-1>=0) {
            if(h[i-1][j]<=h[i][j] && st.find({i-1,j})==st.end()) {
                (rec(h,i-1,j,st));
            }
        }
        else {
            c.push_back(1);
        }
        if(j-1>=0) {
            if(h[i][j-1]<=h[i][j] && st.find({i,j-1})==st.end()) {
                (rec(h,i,j-1,st));
            }
        }
        else {
            c.push_back(1);
        }
        if(j+1<h[0].size()) {
            if(h[i][j+1]<=h[i][j] && st.find({i,j+1})==st.end()) {
                (rec(h,i,j+1,st));
            }
        }
        else {
            c.push_back(2);
        }
        if(i+1<h.size()) {
            if(h[i+1][j]<=h[i][j] && st.find({i+1,j})==st.end()) {
                (rec(h,i+1,j,st));
            }
        }
        else {
            c.push_back(2);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        set<pair<int, int>> st;
        for(int i=0;i<heights.size();i++) {
            for(int j=0;j<heights[0].size();j++) {
                st.clear();
                rec(heights,i,j,st);
                int c1=0;
                int c2=0;
                // cout<<i<<j<<"\n";
                for(auto it:c) {
                    if(it==1) {
                        c1++;
                    }
                    else if(it==2) {
                        c2++;
                    }
                }
                // cout<<c1<<c2;
                if(c1 && c2) {
                    ans.push_back({i,j});
                }
                c.clear();
            }
        }
        
        return ans;
    }
};