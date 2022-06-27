class dlist{
public:
    int key;
    int val;
    dlist* next;
    dlist* prev;
    
    dlist(int key, int val){
        this->key = key;
        this->val = val;
        next = NULL;
        prev = NULL;
    }
};
class LRUCache {
public:
    unordered_map<int, dlist*> mp;
    dlist* head = new dlist(-1, -1);
    dlist* tail = new dlist(-1, -1);
    
    
    int size;
    LRUCache(int capacity) {
        size= capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void insert( dlist* NodeToInsert ){
        NodeToInsert->next = head->next;
        head->next->prev = NodeToInsert;
        head->next = NodeToInsert;
        NodeToInsert->prev = head;
    }
    
    void remove( dlist* node ){
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = NULL; 
        node->prev = NULL;
        
    }
        
    int get(int key) {
        if( mp.find(key)==mp.end()) return -1;
        
        int res = mp[key]->val;
        dlist* resnode = mp[key];
        mp.erase(key);
        remove( resnode);
        insert(resnode);
        mp[key]= head->next;
        return res;
    }
    
    void put(int key_, int value) {
        if( mp.find(key_) != mp.end()){
            dlist* resnode = mp[key_];
            mp.erase(key_);
            resnode->val = value;
            remove(resnode);
        }
        
        if( mp.size()==size){
            mp.erase(tail->prev->key);
            remove(tail->prev);
        }
        
        dlist* node = new dlist(key_, value);
        insert(node);
        mp[key_] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */