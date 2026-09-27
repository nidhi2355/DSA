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
int maxlen=0;
    int longestZigZag(TreeNode* root) {
        if(!root) return maxlen;

        dfs(root->left, true, 1);
        dfs(root->right, false, 1);

        return maxlen;
    }

    void dfs(TreeNode* root, bool isleft, int len){
        if(!root) return;
        maxlen= max(maxlen, len);

        if(isleft){
            dfs(root->right, false, len+1);
            dfs(root->left, true, 1);
        }
        else{
            dfs(root->left, true, len+1);
            dfs(root->right, false, 1);
        }
    }
};