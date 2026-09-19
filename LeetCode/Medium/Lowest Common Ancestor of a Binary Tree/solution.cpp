/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root or root==p or root==q) return root;

        TreeNode* findleft= lowestCommonAncestor(root->left, p, q);

        TreeNode* findright= lowestCommonAncestor(root->right, p, q);

        if(findleft==nullptr) return findright;

        if(findright==nullptr) return findleft;

        return root;
    }
};