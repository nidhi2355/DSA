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
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int maxlen=0;

        dfs(root, maxlen);

        return maxlen;
    }

    int dfs(TreeNode* root, int &maxlen){
        if(!root) return 0;

        int leftlen= dfs(root->left, maxlen);
        int rightlen= dfs(root->right,maxlen);

        maxlen= max(maxlen, leftlen+rightlen);

        return max(leftlen, rightlen)+1;
    }
};