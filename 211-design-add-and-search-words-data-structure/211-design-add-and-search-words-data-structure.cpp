class Trie{
public:
    Trie* children[26];
    bool isLeaf;
    
    Trie(){
        for( int i=0; i<26; i++){
            children[i] = NULL;   
        }
        isLeaf = false;
    }
};

class WordDictionary {
public:
    Trie* root = new Trie();
    WordDictionary() {
    }
    
    void add( string word, Trie* root){
        Trie* currNode  = root;
        for( int i=0; i<word.size(); i++){
            int ind = word[i]-'a';
            if( currNode->children[ind]==NULL){
                currNode->children[ind] = new Trie();
            }
            currNode= currNode->children[ind];
        }
        currNode->isLeaf= true;
    }
    
    bool srch (const char* word, Trie* node){
        for (int i = 0; word[i] && node; i++) {
            if (word[i] != '.') {
                node = node -> children[word[i] - 'a'];
            } else {
                Trie* tmp = node;
                for (int j = 0; j < 26; j++) {
                    node = tmp -> children[j];
                    if (srch(word + i + 1, node)) {
                        return true;
                    }
                }
            }
        }
        return node && node -> isLeaf;
    }
    
    void addWord(string word) {
        add(word, root);
    }
    
    bool search(string word) {
      
        return srch( word.c_str(), root);
    }
    
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */