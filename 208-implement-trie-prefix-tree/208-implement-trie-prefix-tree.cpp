class TrieNode{    
public:    
    char data;
    TrieNode* children[26];
    bool isLeaf;
    TrieNode(char ch) {
        this->data = ch;
        for( int i =0; i< 26; i++){
            children[i] = NULL;
        }
        isLeaf = false;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {       
        root= new TrieNode( '\0');
    }
    
    void trieInsert( TrieNode* root, string word){
        //base case
        if( word.length() == 0){
            root->isLeaf = true;
            return;
        }
        
        TrieNode* child;
        //index 
        int index = word[0] - 'a';
        
        //if present
        if( root->children[index] !=NULL){
            child = root->children[index];
        }
        else{
            //not present
            child = new TrieNode( word[0]);
            root->children[index] = child;
        }
        
        //recursive call
        trieInsert(child, word.substr(1));
        
    }
    void insert(string word) {
        trieInsert( root, word);
    }
    
    bool TrieSearch( TrieNode*  root, string word){
        ///base case
        if( word.length() ==0){
            return root->isLeaf;
        }
        
        //index
        int index = word[0] - 'a';
        TrieNode* child;
        if( root->children[index] !=NULL)
            child = root->children[index];
        else 
            return false;
        
        //recursive call
        return TrieSearch( child, word.substr(1));
    }
    bool search(string word) {
        return TrieSearch( root, word);
    }
    
    bool startpref( TrieNode* root, string pref){
        if ( pref.length()==0){
            return true;
        }
        
        //index
        int index = pref[0]- 'a';
        TrieNode* child;
        
        if( root->children[index]!= NULL){
            child = root->children[index];
        }
        else return false;
        
        //recursion
        return startpref(child, pref.substr(1));
    }
    bool startsWith(string prefix) {
        return startpref( root, prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */