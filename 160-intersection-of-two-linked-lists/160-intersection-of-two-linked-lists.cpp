/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*, bool> mp;
        ListNode* temp= headA;
        while( temp != NULL){
            mp[temp]= true;
            temp = temp->next;
        }
        temp = headB;
        while(temp!= NULL){
            if(mp[temp]==true){
                return temp;
            }
            mp[temp] = true;
            temp= temp->next;
        }
        return NULL;
    }
};