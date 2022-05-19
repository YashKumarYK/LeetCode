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
        
        Node* cloneHead = NULL;
        Node* cloneTail= NULL;
        Node* temp = head;
        while( temp!=NULL){
            insertAtTail( cloneHead, cloneTail, temp->val);
            temp = temp->next;
        }
        
        Node* cloneNode= cloneHead;
        Node*  originalNode= head;
        
        //apraoch1 - using unordered map
        // unordered_map<Node*, Node*> mp;
        // while( originalNode!= NULL){
        //     mp[originalNode] = cloneNode;
        //     cloneNode = cloneNode->next;
        //     originalNode = originalNode->next;
        // }
        // cloneNode=cloneHead;
        // originalNode = head;
        // while( originalNode!=NULL){
        //     cloneNode->random = mp[originalNode->random];
        //     cloneNode = cloneNode->next;
        //     originalNode = originalNode->next;
        // }
        // return cloneHead;
        
        //approach-2 without using map:
        //step 1- make a clone using next - done
        //step 2 - join the clone in between the original
        Node* next = NULL;
        while(  originalNode!=NULL && cloneNode!=NULL){
            //joining original node to the clone node
            next = originalNode->next;
            originalNode->next = cloneNode;
            originalNode= next;
            
            //joining clone node to next original node
            next = cloneNode->next;
            cloneNode->next = originalNode;
            cloneNode = next;
        }
        
        
        //step 3 random ptr
        temp = head;
        while( temp!=NULL ){
            if( temp->next !=  NULL){
                temp->next->random = temp->random? temp->random->next: temp->random;
            }
            temp = temp->next->next;
        }
        
        //STEP 4 separating the list
        
        originalNode= head;
        cloneNode = cloneHead;
        while( originalNode!=NULL &&cloneNode !=NULL){
            originalNode->next = cloneNode->next;
            originalNode = originalNode->next;
            
            if( originalNode!=NULL)
                cloneNode->next = originalNode->next;
            cloneNode = cloneNode->next;
        }
        return cloneHead;
    }
};