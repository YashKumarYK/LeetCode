// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// design the class in the most optimal way

class ListNode{
    public:
    int val;
    int key;
    ListNode* next;
    ListNode* prev;
    
    ListNode(int key, int val){
        this->key = key;
        this->val = val;
    }
};
class LRUCache
{
    private:
    public:
    //Constructor for initializing the cache capacity with the given value.
    unordered_map<int, ListNode*> mp;
    ListNode* head = new ListNode(-1,-1);
    ListNode* tail  = new ListNode(-1,-1);
    int size;
    
    LRUCache(int cap)
    {
        // code here
        size = cap;
        head->next = tail;
        tail->prev = head;
    }
    
    void insert( ListNode* node){
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
    }
    
    void remove( ListNode* node){
        ListNode* prev = node->prev;
        ListNode* next = node->next;
        
        prev->next = next;
        next->prev = prev;
        node->next =NULL;
        node->prev = NULL;
    }
    //Function to return value corresponding to the key.
    int get(int key)
    {
        // your code here
        if( mp.find(key)== mp.end()){
            return -1;
        }
        
        ListNode* resnode= mp[key];
        int res = resnode->val;
        mp.erase(key);
        remove(resnode);
        insert(resnode);
        mp[key]= head->next;
        return res;
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
        if( mp.find(key)!= mp.end()){
            ListNode* resnode = mp[key];
            resnode->val =  value;
            mp.erase(key);
            remove(resnode);
        }
        if( size == mp.size()){
            mp.erase(tail->prev->key);
            remove( tail->prev);
            
        }
        
        ListNode* node = new ListNode(key, value);
        insert( node);
        mp[key]= head->next;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends