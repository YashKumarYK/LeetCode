/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL)
          return {};

        queue<TreeNode*> q;
        vector<vector<int>> v;
        vector<int> ans;
        q.push(root);
        if( q.empty()){
            ans.push_back(NULL);
            v.push_back(ans);
            return v;
        }
        q.push(NULL);
        int i=0;
        int j=0;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if( temp == NULL){
                v.push_back(ans);
                ans.clear();
                if(!q.empty()){
                    q.push(NULL); 
                }
            }
            else{
                ans.push_back(temp->val);
                if( temp->left ) q.push(temp->left);
                if( temp->right) q.push(temp->right);
                
            }
        }
        return v;
    }
};