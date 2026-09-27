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
    int minCameraCover(TreeNode* root) {
        int cameras=0;
        if(!root) return cameras;

        if(dfs(root, cameras)==0) cameras++;

        return cameras;
    }

    int dfs(TreeNode* root, int &cameras){
        if(!root) return 2;

        int leftTree= dfs(root->left, cameras);
        int rightTree= dfs(root->right, cameras);

        if(leftTree==0 or rightTree==0) {
            cameras++;
            return 1;
        }

        if(leftTree==1 or rightTree==1){
            return 2;
        }

        return 0;
    }
};