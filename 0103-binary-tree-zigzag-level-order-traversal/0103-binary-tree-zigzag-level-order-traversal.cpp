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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        if(root==NULL)
        return ans;
        q.push(root);
        int level=0;
        while(!q.empty()){
            
            int s=q.size();
            vector<int>v(s);
            for(int i=0;i<s;i++){
                TreeNode* front=q.front();
                q.pop();
        
                int index = i;
                if(level%2==1){
                    index = s-i-1;
                }
                v[index] = front->val;
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            ans.push_back(v);
            level++;
            
        }
        return ans;
    }
};