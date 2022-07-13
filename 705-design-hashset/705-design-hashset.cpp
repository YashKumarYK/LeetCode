class MyHashSet {
public:
    int num[1000001];
                    
    MyHashSet() {
        memset( num, 0, sizeof(num));
    }
    
    void add(int key) {
        num[key]=1;
    }
    
    void remove(int key) {
        num[key]=0;
    }
    
    bool contains(int key) {
        return num[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */