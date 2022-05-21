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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy =  new ListNode( -1);
        ListNode* tail = dummy;
        ListNode* temp = head->next;
        int sum =0;
        while( temp!= NULL){
            if(  temp->val == 0){
                ListNode* newNode = new ListNode(sum);
                sum =0;
                tail->next= newNode;
                tail = tail->next;
            }
            else{
                sum = temp->val +sum;
            }
            temp = temp->next;
        }
        return dummy->next;
    }
};