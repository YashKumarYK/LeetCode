/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertAtTail( Node* &head, Node* &tail, int val){
        Node* newNode = new Node(val);
        if(!head){
            head = newNode;
            tail = newNode;
            return ;
        } 
        tail->next= newNode;
        tail = newNode;
    }
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        Node* cloneHead = NULL;
        Node* cloneTail= cloneHead;
        Node *temp = head;
        while(temp){
            insertAtTail(cloneHead, cloneTail, temp->val);
            mp[temp] =  cloneTail;
            temp = temp->next;               
        }

        Node* cloneTemp = cloneHead;
        temp = head;

        while(cloneTemp && temp){
            cloneTemp->random = mp[temp->random];
            cloneTemp= cloneTemp->next;
            temp = temp->next;
        }

        return cloneHead;
        
        
    }
};