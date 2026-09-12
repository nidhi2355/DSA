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
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;

        return helper(root->left, root->right);
    }

    bool helper(TreeNode* leftroot, TreeNode* rightroot){
        if(!leftroot and !rightroot) return true;

        if(!leftroot or !rightroot) return false;

        return (leftroot->val == rightroot->val) and helper(leftroot->left, rightroot->right) and helper(leftroot->right, rightroot->left);
    }
};