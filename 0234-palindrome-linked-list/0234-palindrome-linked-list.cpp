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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast){
            fast = fast->next;
            if(fast) fast = fast->next;
            slow = slow->next;
        }
        cout<<slow->val;
        ListNode* start = head;
        ListNode* temp = reverse(slow);
        while(temp){
            if(start->val!= temp->val) return false;
            start = start->next;
            temp = temp->next;
        }
        return true;
    }
};