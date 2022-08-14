class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_map<string, int> mp;
        
        for( auto i: wordList) mp[i]++;
        queue<string> q;
        q.push( beginWord);
        int cnt =1;
        while(!q.empty()){
            int size = q.size();
            for( int i=0; i<size; i++){
                string word = q.front();
                q.pop();
                
                if(mp.find(word)!= mp.end()){
                    mp.erase(word);
                }
                if( word==endWord) return cnt;
                
                for( int j=0; j<word.size(); j++){
                    string w = word;
                    for( int k =0; k<26; k++){
                        w[j] =  'a'+ k;
                        
                        if( mp.find(w)!=mp.end()){                        
                            q.push(w);
                        }
                    }
                }
            }   
            cnt++;
        }
        return 0;
    }
};