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
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        return validateTree(root, LLONG_MIN, LLONG_MAX);
    }

    bool validateTree(TreeNode* root, long long minval, long long maxval){
        if(!root) return true;

        if(root->val > minval and root->val < maxval){
            return validateTree(root->left, minval, root->val) and validateTree(root->right, root->val, maxval);
        }
        return false;
    }
};