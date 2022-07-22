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
        
        //lets make two linkedlist;
        ListNode* smaller_head= new ListNode(0);
        ListNode* smaller_tail= smaller_head;
        ListNode* larger_head= new ListNode(0);
        ListNode* larger_tail= larger_head;
        ListNode* temp = head;
        while(temp!=NULL){
            if( temp-> val < x ){
                smaller_tail-> next = temp;
                smaller_tail = smaller_tail->next;
            }
            else{
                larger_tail-> next = temp;
                larger_tail = larger_tail->next;
            }
            temp= temp->next;
            
        }
        larger_tail->next= NULL;
        smaller_tail->next = larger_head->next;
        return smaller_head->next;
    }
};