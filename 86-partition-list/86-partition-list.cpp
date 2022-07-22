/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if( head==NULL || head->next==NULL) return head;
        ListNode* d1 = new ListNode(0);
        ListNode* t1 = d1;
        ListNode* d2 = new ListNode(0);
        ListNode* t2=d2;
        ListNode* temp = head;
        while( temp!= NULL){
            ListNode* newNode= new ListNode( temp->val);
            if( temp->val <x){
                t1->next = newNode;
                t1= newNode;
                cout<< "t1 -"<< newNode->val<<endl;
            }
            else{
                t2->next= newNode;
                t2 = newNode;
                cout<< "t2 -"<< newNode->val<<endl;
            }
            
            temp = temp->next;
        }
        
        if( d1->next == NULL)
            return d2->next;
        t1->next = d2->next;       
        return d1->next;
    }
};