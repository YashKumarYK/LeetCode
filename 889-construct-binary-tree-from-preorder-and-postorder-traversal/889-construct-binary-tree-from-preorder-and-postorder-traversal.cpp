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
    
//     TreeNode* solve( vector<int>& preorder, vector<int>& postorder, int n, int ind, map<int, int> &mp, vector<int> &vis){
//         if( ind ==n-1 || vis[preorder[i]] ==1) return NULL;
//         vis[preorder[i]] = 1;
        
//         //adding a node
//         int element = preorder[ind];
//         TreeNode* root = new Tr eeNode(element);
//         int pos = mp[element] -1;
        
//         root->left = solve( preorder, postorder, n, ind+1, mp)
//         root->right = solve( preorder, postorder, n, pos)
    
//     }
//     TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
//         // lets make a visited array
//         int n = preorder.size();
//         vector<int> vis( n+1, 0);
//         map<int, int> mp;
//         for(int i=0; i<n; i++){
//             mp[postorder[i]] = i;
//         }
        
//         int ind =0;
//         TreeNode* root = solve( preorder, postorder, n, ind, mp, vis);
//         return root;
//     }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder){
        int n = preorder.size();
        vector<int> po(n+1,0);
        vector<int> pe(n+1,0);
        
        
        if( n==0) return NULL;
        for(int i=0; i<n; i++){
            po[postorder[i]] = i;
            pe[preorder[i]] = i;
        }
        
        vector<int> vis( n+1, 0);
        TreeNode* root = new TreeNode( preorder[0]);
        queue<TreeNode*> q;
        q.push( root);
        vis[root->val]=1;
        while( !q.empty()){
            TreeNode* front = q.front();
            q.pop();
            int left = pe[front->val]+1;
            int right = po[front->val]-1;
            front->left = left>n-1 || vis[preorder[left]]==1? NULL: new TreeNode( preorder[left]);
            front->right = right<0 || vis[postorder[right]]==1|| preorder[left] ==postorder[right]? NULL: new TreeNode( postorder[right]);
            
            if( front->left && !vis[front->left->val]){
                q.push( front->left);
                vis[front->left->val]=1;
            }
                
            if( front->right && !vis[front->right->val]){
                q.push(front->right);
                vis[front->right->val]=1;
            }
        }
        return root;
    }
};