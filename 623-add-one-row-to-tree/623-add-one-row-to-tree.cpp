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

    void my_solve(TreeNode* curr, int val, int d)
    {
        d--;
        if(d==0)
        {
            TreeNode* leftnxt = curr->left;
            TreeNode* rghtnxt = curr->right;
            curr->left = new TreeNode(val);
            curr->right = new TreeNode(val);
            curr->left->left = leftnxt;
            curr->right->right = rghtnxt;
            d++;
            return;
        }
        if(curr->left!=NULL)
            my_solve(curr->left, val, d);
        if(curr->right!=NULL)
            my_solve(curr->right, val, d);
        d++;
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1)
        {
            TreeNode* new_node = new TreeNode(val);
            new_node->left = root;
            return new_node;
        }
        TreeNode* curr = root;
        my_solve(curr, val, depth-1);
        return root;
    }
};