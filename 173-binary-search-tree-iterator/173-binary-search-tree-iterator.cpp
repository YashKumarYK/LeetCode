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
class BSTIterator {
public:
    vector<int> v;
    int it;
    BSTIterator(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* curr = root;
        while( curr!=NULL || !s.empty()){
            while( curr !=NULL){
                s.push(curr);
                curr= curr->left;
            }
            
            curr= s.top();
            s.pop();
            v.push_back(curr->val);
            curr = curr->right;
        }
        
        it = 0;
    }
    
    int next() {
        return v[it++];
    }
    
    bool hasNext() {
        return it<v.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */