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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        int cnt =1;
        ListNode *tail = head;
        while(tail->next){
            tail= tail->next;
            cnt++;
        }
        k = k%cnt;
        if(k==0) return head;
        ListNode *temp = head;
        for(int i=0;i<cnt-k-1; i++){
            temp= temp->next;
        }
        ListNode* next = temp->next;
        temp->next=NULL;
        tail->next = head;
        head= next;
        return head;
    }
};