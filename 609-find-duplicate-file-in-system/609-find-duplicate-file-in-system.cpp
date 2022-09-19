class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> mp;
        string pathName = "", fileName = "", content = "", pathUrl = "";
        int spaceInd, contentInd1, contentInd2;
        vector<vector<string>> ans;
        
        for(string &s: paths) {
            spaceInd = s.find(" ");
            pathName = s.substr(0, spaceInd);
            
            for(int i=spaceInd+1; i<s.size(); i++) {
                if(s[i] == ' ') {
                    spaceInd = i;
                }
                if(s[i] == '(') {
                    contentInd1 = i;
                    fileName = s.substr(spaceInd+1, (contentInd1-spaceInd-1));
                }
                if(s[i] == ')') {
                    contentInd2 = i;
                    string content = s.substr(contentInd1+1, (contentInd2-contentInd1-1));
                    pathUrl = pathName + "/" + fileName;
                    mp[content].push_back(pathUrl);
                }
            }
        }
        
        
        for(auto x: mp) {
            vector<string> contentVec;
            if(x.second.size() == 1) continue;
            for(auto v: x.second) {
                contentVec.push_back(v);
            }
            ans.push_back(contentVec);
        }
        
        return ans;
    }
};