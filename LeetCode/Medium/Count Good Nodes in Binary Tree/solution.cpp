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
int cnt=0;
    int goodNodes(TreeNode* root) {
        cnt++;

        dfs(root->left, root->val);
        dfs(root->right, root->val);

        return cnt;
    }

    void dfs(TreeNode* root, int maxval){
        if(!root) return;
        if(root->val >= maxval) cnt++;
        maxval= max(maxval, root->val);
        dfs(root->left, maxval);
        dfs(root->right, maxval);
    }
};