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

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0; i<inorder.size(); i++){
            in[inorder[i]]= i;
        }

        TreeNode* root= helper(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);

        return root;
    }

    TreeNode* helper(vector<int> &inorder, int instart, int inend, vector<int> &postorder, int poststart, int postend){
        if(instart> inend or poststart>postend) return nullptr;

        TreeNode* root= new TreeNode(postorder[postend]);

        int inroot= in[root->val];
        int rem= inroot-instart;
        
        root->left= helper(inorder, instart, inroot-1, postorder, poststart, poststart+rem-1);
        root->right= helper(inorder, inroot+1, inend, postorder, poststart+rem, postend-1);

        return root;
    }
};