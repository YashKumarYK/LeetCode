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
    void insertatTail(Node* & cloneTail, Node* &cloneHead, int val){
        Node* newNode = new Node(val);
        if(cloneHead==NULL){
            cloneTail = newNode;
            cloneHead = newNode;
            return;
        }
        cloneTail->next = newNode;
        cloneTail = newNode; 
    }
    Node* copyRandomList(Node* head) {
        Node* cloneNode=NULL;
        Node* cloneTail = NULL;
        Node* cloneHead = NULL;
        Node* temp =head;
        while(temp){
            insertatTail(cloneTail,cloneHead, temp->val);
            temp = temp->next;
        }

        //joining both LL
        Node* curr = head;
        Node* cloneCurr = cloneHead;
        while(curr && cloneCurr){
            Node* currnext = curr->next;
            curr->next = cloneCurr;
            
            Node* cloneNext = cloneCurr->next;
            cloneCurr->next = currnext;
            
            curr = currnext;
            cloneCurr = cloneNext;
            
        }

        temp= head;
        while(temp){
            if(temp->next)
                temp->next->random = temp->random? temp->random->next: temp->random;
            
            temp= temp->next->next;
        }
        
        curr = head;
        cloneCurr = cloneHead;
        while(curr && cloneCurr){
            curr->next = curr->next->next;

            cloneCurr->next = cloneCurr->next?cloneCurr->next->next:cloneCurr->next;
            
            curr = curr->next;
            cloneCurr = cloneCurr->next;

        }

        return cloneHead;
    }
};


// 1->2->3->4->5->6

// 1->2->3->4->5->6

// curr->next->random = curr->random->next;