/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;
        q.push(root);
        vector<vector<int>> ans;
        if( !root) return ans;
        while( !q.empty()){
            vector<int> v;
            int size =q.size();
            for( int i=0; i<size; ++i){
                Node* front = q.front();
                q.pop();
                v.push_back(front->val);
                for( auto i: front->children){
                    q.push(i);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};