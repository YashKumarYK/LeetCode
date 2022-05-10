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
    void createMapping(vector<int>& inorder, int n, map<int, int> &nodeToIndex ){
        for(int i=0; i<n; i++){
            nodeToIndex[inorder[i]]=i;
        }
    }
    
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int &index, int n, int inorderstart, int inorderend, map<int, int> & nodeToIndex){
        if ( index<0 || inorderstart > inorderend)
            return NULL;
    
        int element = postorder[index--];
        TreeNode* root = new TreeNode(element);
        int position = nodeToIndex[element];
        
        
        root->right = solve(inorder, postorder,index, n,  position+1,inorderend, nodeToIndex);

        root->left = solve(inorder, postorder, index, n, inorderstart, position-1, nodeToIndex);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n= postorder.size();
        int index = n-1;
        map<int, int> nodeToIndex;
        createMapping( inorder, n, nodeToIndex);
        TreeNode* ans = solve(inorder, postorder, index, n, 0, n-1, nodeToIndex);
        return ans;
    }
};