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
    void deletenode( ListNode* &head, int pos){
        if ( pos==0){
            ListNode* temp = head;
            head= head->next; 
            temp-> next = NULL;
            return;
        }
        ListNode* prev = head;
        for( int i=0; i< pos-1; i++){
            prev=prev->next;
        }
        prev-> next= prev->next->next;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if( n==1 && head->next ==NULL){
            return NULL;
        }
        ListNode* temp= head;
        int cnt=0;
        while( temp!= NULL){
            cnt=cnt+1;
            temp= temp-> next;
        }
        int pos= cnt-n;
        deletenode( head, pos);
        return head;
    }
};