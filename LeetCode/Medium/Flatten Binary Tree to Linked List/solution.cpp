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
    void flatten(TreeNode* root) {
        if(!root) return;
        
        vector<TreeNode*> preorder;

        stack<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            preorder.push_back(q.top());
            q.pop();

            if(preorder.back()->right) q.push(preorder.back()->right);
            if(preorder.back()->left) q.push(preorder.back()->left);
        }

        for(int i=0; i<preorder.size()-1; i++){
            preorder[i]->right= preorder[i+1];
            preorder[i]->left= nullptr;
        }

        preorder[preorder.size()-1]->right= nullptr;
        preorder[preorder.size()-1]->left= nullptr;
        
    }
};