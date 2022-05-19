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
        if(head==NULL||head ->next ==NULL) return head;
        ListNode* curr= head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while( curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr= next;
        }
        return prev;
    }
    void insertAtTail(ListNode* &anshead, ListNode* &anstail, int digit){
        ListNode* temp=new ListNode( digit);
        if( anshead==NULL){
            anshead= temp;
            anstail= temp;
            return;
        }
        anstail->next= temp;
        anstail = temp;
    }
    ListNode* addlist(ListNode* l1, ListNode* l2){
        ListNode* anshead = NULL;
        ListNode* anstail= NULL;
        int sum;
        int carry=0;
        int digit;
        ListNode* curr1= l1;
        ListNode* curr2 = l2;
        while(curr1!=NULL ||curr2!=NULL || carry !=0){
            int val1 =0;
            if(curr1!=NULL)
                val1= curr1->val;
            
            int val2 =0;
            if( curr2!=NULL)
                val2= curr2->val;
            
            sum = val1 +val2 +carry;
            
            digit= sum%10;
            insertAtTail(anshead, anstail, digit);
            carry = sum/10;
            if( curr1!=NULL){
                curr1= curr1->next;
            }
            if(curr2!=NULL){
                curr2=curr2->next;
            }
        }
        return anshead;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //reverse the list 
        // l1= reverse(l1);
        // l2= reverse(l2);
        
        ListNode* ans = addlist( l1, l2);
        // ans = reverse(ans);
        return ans;
    }
};