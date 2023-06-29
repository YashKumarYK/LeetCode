class Solution {
public:
    // int arr[5] = {1, 0, -1, 0, 1};
    // int shortestPathAllKeys(vector<string>& grid) {
    //     int n = grid.size();
    //     int m = grid[0].size();
    //     int x=0, y =0;
    //     int maxlen =-1;
    //     for(int i=0;i<n; i++){
    //         for(int j =0;j<m;j++){
    //             if(grid[i][j]=='@'){
    //                 x =i, y =j;
    //             }
    //             if(grid[i][j]>='a' && grid[i][j]<='z'){
    //                maxlen = max(maxlen, grid[i][j]-'a'+1);
    //             }
    //         }
    //     }
    //     unordered_map<string, int> mp;
    //     queue<pair<pair<int,int>, int>> q;
    //     string s= to_string(x)+" "+to_string(y)+" "+ to_string(0);
    //     q.push({{x,y},0});
    //     int count =0;
    //     while(!q.empty()){
    //         int s = q.size();
    //         for(int i=0; i<s; i++){
    //             int x = q.front().first.first;
    //             int y = q.front().first.second;
    //             int key = q.front().second;
    //             q.pop();
    //             if(key ==(1<<maxlen)-1) return count;

    //             for(int k=0;k<4;k++){
    //                 int nx = arr[k]+x;
    //                 int ny = arr[+k+1]+y;
    //                 if(nx>=0 && ny>=0 && nx<n && ny<m){
    //                     char ch = grid[nx][ny];
    //                     if(ch =='#') continue;

    //                     if(ch>='a' && ch<='f'){
    //                         key |= 1<<(ch-'a');
    //                     }

    //                     if(ch>='A' && ch<='Z' && ((key>>(ch-'A'))&1)==0) continue;
                        
    //                     string s = to_string(nx)+" "+ to_string(ny)+" "+ to_string(key);
    //                     if(!mp.count(s)){
    //                         mp[s]++;
    //                         q.push({{nx,ny}, key});
    //                     }
    //                 }
    //             }
    //         }
    //         count++;
    //     }
    //     return -1;
    // }
    int shortestPathAllKeys(vector<string>& grid) {
        int x = -1, y = -1, m = grid.size(), n = grid[0].size(), max_len = -1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                char c = grid[i][j];
                if (c == '@') {
                    x = i;
                    y = j;
                }
                if (c >= 'a' && c <= 'f') {
                    max_len = max(c - 'a' + 1, max_len);
                }
            }
        }
        vector<int> start = {0, x, y};
        queue<vector<int>> q;
        unordered_set<string> visited;
        visited.insert(to_string(0) + " " + to_string(x) + " " + to_string(y));
        q.push(start);
        int step = 0;
        vector<vector<int>> dirs {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            int size = q.size();
            for (int k = 0; k < size; ++k) {
                vector<int> curr = q.front();
                q.pop();
                if (curr[0] == (1 << max_len) - 1)
                    return step;
                for (auto &d : dirs) {
                    int i = curr[1] + d[0];
                    int j = curr[2] + d[1];
                    int keys = curr[0];
                    if (i >= 0 && i < m && j >= 0 && j < n) {
                        char c = grid[i][j];
                        if (c == '#') continue;
                        if (c >= 'a' && c <= 'f')
                        keys |= 1 << (c - 'a');
                        if (c >= 'A' && c <= 'F' && ((keys >> (c - 'A')) & 1) == 0) {
                            continue;
                        }
                        if (!visited.count(to_string(keys) + " " + to_string(i) + " " + to_string(j))) {
                            visited.insert(to_string(keys) + " " + to_string(i) + " " + to_string(j));
                        q.push({keys, i, j});
                    }
                }
            }
            }
            ++step;
        }
        return -1;
    }
};