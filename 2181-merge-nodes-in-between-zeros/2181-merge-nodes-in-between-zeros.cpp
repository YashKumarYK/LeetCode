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
//         //aproach-1 using a dummy linked list
//         //T.C - O(N)
//         //SC- O(N)
//         ListNode* dummy =  new ListNode( -1);
//         ListNode* tail = dummy;
//         ListNode* temp = head->next;
//         int sum =0;
//         while( temp!= NULL){
//             if(  temp->val == 0){
//                 ListNode* newNode = new ListNode(sum);
//                 sum =0;
//                 tail->next= newNode;
//                 tail = tail->next;
//             }
//             else{
//                 sum = temp->val +sum;
//             }
//             temp = temp->next;
//         }
//         return dummy->next;
        
        //approach 2 - 
        int sum =0;
        ListNode* curr= head->next;
        ListNode* temp = curr;
        while( temp!=NULL){
            if( temp->val ==0){
                curr->val = sum;
                curr->next = temp ->next;
                curr= curr->next;
                sum = 0;
            }
            else{
                sum = sum+temp->val;
            }
            temp= temp->next;
        }
        return head->next;
    }
};