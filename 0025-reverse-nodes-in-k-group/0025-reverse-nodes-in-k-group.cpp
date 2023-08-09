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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return NULL;
        ListNode* curr = head;
        int i =0;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        ListNode* temp = head;
        int cnt =0;
        while(temp){
            temp = temp->next;
            cnt++;
        }

        while(curr!=NULL && i<k && cnt>=k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr= next;

            i++;
        }
        if(cnt<k){
            prev = curr;
            curr =  curr->next;
        }

        if(next!=NULL && cnt>=k)
            head->next = reverseKGroup(next, k);
        return prev;
    }
};