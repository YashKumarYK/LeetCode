class Solution {
public:
    static bool comp(string&a, string&b){
        return a.length()<b.length();
    }

    unordered_map<string, int> ans;
    int solve(string word, unordered_map<string, int> &mp){
        if(word.size()==0) return 0;
        

        if(ans.count(word)) return ans[word];
        int maxi =0;

        for(int i=0;i<word.size();i++){
            string st = word.substr(0,i)+ word.substr(i+1);
            if(mp.count(st))
                maxi = max(maxi, 1+solve(st,mp));
        }
        return ans[word] = maxi;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), comp);
        unordered_map<string, int> mp;
        for( auto str: words){
            mp[str]++;
        }
        int maxi = 0;
        for( auto str: words){
            cout<<str<<" ";
            maxi = max(maxi, solve(str, mp));
        }
        return maxi+1;
    }
};