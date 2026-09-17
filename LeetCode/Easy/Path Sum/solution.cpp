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
    bool hasPathSum(TreeNode* root, int target) {
        if(!root) return false;
        return PathSum(root, target);
    }

    bool PathSum(TreeNode* root, int target){
        if(!root->left and !root->right){
            if(target==root->val) return true;
            return false;
        }

        bool l= false, r= false;
        if(root->left){
            l= PathSum(root->left, target- root->val);
        }

        if(root->right){
            r= PathSum(root->right, target- root->val);
        }

        return l or r;
    }
};