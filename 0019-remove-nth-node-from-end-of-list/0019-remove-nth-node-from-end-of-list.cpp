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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //to handle edge cases confortably, make a dummy node
        ListNode* dummy = new ListNode(0);
        
        ListNode* fast= dummy;
        ListNode* slow= dummy;
        dummy->next = head;

        for(int i=0;i<n+1;i++){
            fast= fast->next;
        }
        while(fast!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next= slow->next->next;
        return dummy->next;
    }
};

// ListNode* start = new ListNode(0);
//         ListNode* slow = start;
//         ListNode* fast= start;
//         start->next = head;

//         for(int i=0; i<n+1; i++){
//             fast = fast->next;
//         }

//         while( fast!= NULL){
//             slow = slow->next;
//             fast = fast->next;
//         }
//         slow->next = slow->next->next;
//         return start->next;
//     }