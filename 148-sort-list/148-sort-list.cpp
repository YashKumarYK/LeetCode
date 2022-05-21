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
    
    ListNode* getMiddle( ListNode* head){
        ListNode* fast = head->next;
        ListNode* slow = head;
        while( fast!=NULL && fast->next !=NULL){
            fast = fast->next;
            if( fast!=NULL){
                fast = fast->next;
            }
            slow = slow->next;
        }
        return slow;
    }
    
    ListNode* merge2lists( ListNode* left, ListNode* right){
        if( right ==NULL) return left;
        if( left==NULL) return right;
        
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;
        while( left !=NULL && right !=NULL){
            if( left->val < right->val){
                tail->next = left;
                tail= left;
                left = left->next;
            }
            else{
                tail->next = right;
                tail= right;
                right = right->next;
            }
        }
        while(left !=NULL){
            tail->next = left;
            tail= left;
            left = left->next;
        }
        
        while(right !=NULL){
            tail->next = right;
            tail= right;
            right = right->next;
        }
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if( head ==NULL || head->next==NULL) return head;
        ListNode* mid = getMiddle( head);
        
        ListNode* left = head;
        ListNode* right = mid->next;
        
        mid->next = NULL;
        
        //RECURSIVE CALL
        left = sortList(left);
        right = sortList(right);
        
        //merge two sorted array
        ListNode* mergeList = merge2lists( left, right);
        
        return mergeList;
    }
};