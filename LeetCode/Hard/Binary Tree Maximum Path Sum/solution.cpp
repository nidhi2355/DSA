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
    int sum=INT_MIN;

    int maxPathSum(TreeNode* root) {
        if(!root) return 0;

        pathSum(root);

        return sum;
    }

    int pathSum(TreeNode* root){
        if(!root) return INT_MIN;

        int leftsum= max(0, pathSum(root->left));

        int rightsum= max(0, pathSum(root->right));

        sum= max(sum, leftsum+rightsum+root->val);

        return max(leftsum, rightsum)+root->val;
    }
};