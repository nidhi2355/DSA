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
    unordered_map<int, int> in;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        for(int i=0; i<inorder.size(); i++){
            in[inorder[i]]= i;
        }

        return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }

    TreeNode* build(vector<int> &preorder, int prestart, int preend, vector<int> &inorder, int instart, int inend){
        if(prestart>preend or instart>inend) return nullptr;

        TreeNode* root= new TreeNode(preorder[prestart]);

        int inroot= in[preorder[prestart]];
        int rem= inroot-instart;

        root->left= build(preorder, prestart+1, prestart+rem, inorder, instart, inroot-1);

        root->right= build(preorder, prestart+rem+1, preend, inorder, inroot+1, inend);

        return root;
    }
};