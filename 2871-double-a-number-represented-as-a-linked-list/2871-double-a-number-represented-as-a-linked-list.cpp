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
    ListNode* reverse(ListNode* head){
        if(!head || !head->next) return head;
        
        ListNode* h2 = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return h2;
    }
    ListNode* doubleIt(ListNode* head) {
        if(!head) return NULL;
        head = reverse(head);
        int carry =0;
        ListNode* temp = head;
        while(temp){
            int val = temp->val*2+carry;
            carry = val/10;
            temp->val = val%10;
            temp= temp->next;
        }
        head = reverse(head);
        if(carry){
            ListNode* newNode = new ListNode(1);
            newNode->next = head;
            head = newNode;
        }
        
        return head;
    }
};