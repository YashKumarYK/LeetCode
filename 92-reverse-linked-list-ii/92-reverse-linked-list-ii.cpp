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
    
    ListNode* reverse( ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        
        while( curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* temp = head;
        int cnt =1;
        ListNode* next = NULL;
        while(cnt<right){
            temp = temp->next;
            cnt++;
        }
        next = temp->next;
        temp->next = NULL;
        cnt =1;
        temp= head;
        while( cnt<left-1){
            temp= temp->next;
            cnt++;
        }
        if( left ==1){
            head = reverse(head);
        }
        else{
            ListNode* curr = temp->next;
            temp->next = reverse(curr);
        }
        temp= head;
        cnt =1;
        while(cnt<right){
            temp = temp->next;
            cnt++;
        }
        temp->next = next;
        
        return head;
    }
};