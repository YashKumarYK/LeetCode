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

 class comp{
     public:
     bool operator()(ListNode*a, ListNode*b){
         return a->val> b->val;
     }
 };
class Solution {
public:
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, comp> pq;
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        for( auto &ll: lists){
            if(ll) pq.push(ll);
        }

        while(!pq.empty()){
            ListNode* top = pq.top();
            pq.pop();
            tail->next = top;
            if(top->next){
                pq.push(top->next);
            }
            tail = tail->next;
        }
        return dummy->next;
    }
};