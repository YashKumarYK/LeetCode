class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b){
        return a[1]<b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        // to get the maximum pairs we need to end the right early so we need to check idf ends as earliesr as possible. so sort the pairs acc. to right; 
        sort(pairs.begin(), pairs.end(), comp);   
        int cnt = 1;
        int n = pairs.size();
        int curr = pairs[0][1];
        for(int i=1;i<n; i++){
            if(curr<pairs[i][0]){
                cnt++;
                curr = pairs[i][1];
            }
        }
        return cnt;
    }
};