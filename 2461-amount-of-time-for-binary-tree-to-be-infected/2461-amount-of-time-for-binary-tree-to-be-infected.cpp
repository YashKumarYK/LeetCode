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

    //function inorder
    void inorder(TreeNode* root, int start,TreeNode*& start_Node,
    unordered_map<TreeNode*, TreeNode*>& Parent){
    /*
    base 
    */
        if(root==NULL) return ;
        if(root->val==start)
           start_Node=root;
        
        if(root->left)
        {
            Parent[root->left]=root;
            inorder(root->left,start,start_Node,Parent);
        }

         if(root->right)
        {
            Parent[root->right]=root;
            inorder(root->right,start,start_Node,Parent);
        
        }
    
    }

    int amountOfTime(TreeNode* root, int start) {
        queue<TreeNode*>q;
        unordered_map<TreeNode*, TreeNode*> Parent;
        TreeNode* start_Node=NULL;
        inorder(root, start, start_Node, Parent);
        Parent[root]=NULL;
        q.push(start_Node);
        int t=0;
        unordered_map<TreeNode*, bool> visited;
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++)
            {
                 TreeNode* f=q.front();
                 q.pop();
                 visited[f]=true;
                 //3 directions for travelling

                 //1. first direction left node
                 if(f->left && !visited[f->left])
                 q.push(f->left);


                 //2. second direction right node;
                 if(f->right && !visited[f->right])
                 q.push(f->right);

                //3. third direction parent node
                 if(Parent[f] && !visited[Parent[f]]){
                     q.push(Parent[f]);
                 }

            }
            t++;
        }
        return t-1;
    }
};
