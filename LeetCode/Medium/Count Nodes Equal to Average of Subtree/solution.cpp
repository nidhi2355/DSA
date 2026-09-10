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
    int cnt;

    int averageOfSubtree(TreeNode* root) {
        if(!root) return 0;

        cnt=0;

        findNodes(root);

        return cnt;
    }

    pair<int, int> findNodes(TreeNode* root){
        if(!root) return {0, 0};

        pair<int, int> leftTree= findNodes(root->left);
        pair<int, int> rightTree= findNodes(root->right);

        int nodes= leftTree.second+ rightTree.second+1;
        int sum= leftTree.first+ rightTree.first+ root->val;

        if(root->val == sum/nodes) cnt++;

        return {sum, nodes};
    }
};