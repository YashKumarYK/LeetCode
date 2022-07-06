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
    
    ListNode* reverse( ListNode* head){
        ListNode* next = NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;
        
        while( curr!= NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        // vector<int> v;
        // ListNode* temp = head;
        // while( temp!=NULL){
        //     v.emplace_back(temp->val);
        //     temp = temp->next;
        // }
        // int n = v.size();
        // int i=0;
        // int j = n-1;
        // int maxi = INT_MIN;
        // while( i<j){
        //     maxi = max(maxi, v[i]+ v[j]);
        //     i++, j--;
        // }
        // return maxi;
        
        //second approach
        ListNode* fast= head;
        ListNode* slow = head;
        while( fast->next!= NULL && fast->next->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        cout<<slow->val<<endl;
        
        ListNode* mid = reverse( slow->next);
        ListNode* temp = head;
        
        int maxi = INT_MIN;
        // mid= mid->next;
        
        while( mid!= NULL){
            maxi = max(maxi, temp->val + mid->val);
            temp= temp->next;
            mid = mid->next;
        }
        return maxi;
    }
};