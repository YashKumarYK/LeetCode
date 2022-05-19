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
    ListNode* reverse( ListNode* &head){
        ListNode* curr= head;
        ListNode* prev= NULL;
        ListNode* next = NULL;
        while( curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr= next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next ==NULL) return true; 
        ListNode* fast = head->next;
        ListNode* slow = head;
        while( fast!= NULL && fast->next !=NULL){
            fast = fast->next;
            if(fast->next!=NULL){
                fast = fast->next;
            }
            slow = slow->next;
        }
        ListNode* temp= slow->next;
        slow->next = reverse(temp);
        
        ListNode* h1= head;
        ListNode* h2= slow->next;
        while(h1!=NULL&& h2!=NULL){
            if( h1->val != h2->val){
                return false;
            }
            h1= h1->next;
            h2= h2->next;
        }
        return true;
    }
};