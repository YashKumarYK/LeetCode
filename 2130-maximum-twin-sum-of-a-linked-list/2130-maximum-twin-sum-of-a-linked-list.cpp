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
    int pairSum(ListNode* head) {
        vector<int> v;
        ListNode* temp = head;
        while( temp!=NULL){
            v.emplace_back(temp->val);
            temp = temp->next;
        }
        int n = v.size();
        int i=0;
        int j = n-1;
        int maxi = INT_MIN;
        while( i<j){
            maxi = max(maxi, v[i]+ v[j]);
            i++, j--;
        }
        return maxi;
    }
};