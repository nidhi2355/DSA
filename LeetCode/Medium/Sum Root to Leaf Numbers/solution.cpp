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
    int sumNumbers(TreeNode* root) {
        int ans=0, curr=0;
        if(!root) return ans;
        dfs(root, curr, ans);
        return ans;
    }

    void dfs(TreeNode* root, int curr, int &ans){
        curr*=10;
        curr+= root->val;

        if(!root->left and !root->right){
            ans+= curr;
            return;
        }

        if(root->left){
            dfs(root->left, curr, ans);
        }

        if(root->right){
            dfs(root->right, curr, ans);
        }

        return;
    }
};