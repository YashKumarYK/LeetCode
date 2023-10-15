class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        vector<string> ans;
        unordered_map<string,int> mp;
        ans.push_back(words[0]);
        int prev= 0;
        for(int i=1;i<n;i++){
            if(groups[i]!= groups[prev]){
                prev = i;
                ans.push_back(words[i]);
            }
        }
        return ans;
        
    }
};