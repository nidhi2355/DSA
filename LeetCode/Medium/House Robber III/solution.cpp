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
int maxans=0;
    int rob(TreeNode* root) {
        findPaths(root);

        return maxans;
    }

    // pick, notpick
    pair<int, int> findPaths(TreeNode* root){
        if(!root) return {0, 0};

        pair<int, int> leftTree= findPaths(root->left);
        pair<int, int> rightTree= findPaths(root->right);

        int pick= root->val+ leftTree.second+ rightTree.second;

        int notpick= max(leftTree.first, leftTree.second)+ max(rightTree.first, rightTree.second);

        maxans= max({maxans, pick, notpick});

        return {pick, notpick};
    }
};