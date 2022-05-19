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
        Node* newNode= new Node(val);
        if( head ==NULL){
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        tail= tail->next;
    }
    Node* copyRandomList(Node* head) {
        //apraoch1 - using unordered map
        Node* cloneHead = NULL;
        Node* cloneTail= NULL;
        Node* temp = head;
        while( temp!=NULL){
            insertAtTail( cloneHead, cloneTail, temp->val);
            temp = temp->next;
        }
        
        Node* cloneNode= cloneHead;
        Node*  originalNode= head;
        
        unordered_map<Node*, Node*> mp;
        while( originalNode!= NULL){
            mp[originalNode] = cloneNode;
            cloneNode = cloneNode->next;
            originalNode = originalNode->next;
        }
        cloneNode=cloneHead;
        originalNode = head;
        while( originalNode!=NULL){
            cloneNode->random = mp[originalNode->random];
            cloneNode = cloneNode->next;
            originalNode = originalNode->next;
        }
        return cloneHead;
    }
};