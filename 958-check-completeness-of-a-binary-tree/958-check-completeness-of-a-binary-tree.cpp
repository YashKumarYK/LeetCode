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
    int countnode( TreeNode* root){
        if( root ==NULL) return 0;
        
        int ans = 1+ countnode(root->left)+countnode( root->right);
        return ans;
    }
    
    bool isCBT( TreeNode* root, int index, int nodecounts){
        if( root == NULL) return true;
        if( index>=nodecounts){
            return false;
        }
        else{
            bool left = isCBT(root->left, 2*index+1, nodecounts);
            bool right = isCBT(root->right, 2*index +2, nodecounts);
            return (left && right);
        }
    }
    bool isCompleteTree(TreeNode* root) {
        int index =0;
        int nodecounts= countnode(root);
        bool ans = isCBT( root, index, nodecounts);
        return ans;
    }
};