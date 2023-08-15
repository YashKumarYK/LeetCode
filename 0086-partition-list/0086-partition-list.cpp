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
        ListNode* smaller = new ListNode(-1000);
        smaller->next = head;
        ListNode* temp = head;
        ListNode* prev = smaller;
        ListNode* greater = new ListNode(-1000);
        ListNode* greaterTail = greater;

        while(temp!=NULL){
            while(temp!=NULL &&  temp->val>=x){
                greaterTail->next= temp;
                greaterTail = temp;
                temp = temp->next;
            }
            if(temp){
                prev->next = temp;
                prev = temp;
                temp = temp->next;

            }
                

        }
        prev->next = greater->next;
        greaterTail->next = NULL;
        return smaller->next;
    }
};