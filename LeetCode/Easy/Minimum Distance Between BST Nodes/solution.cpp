class Solution {
    int minDiff = INT_MAX;
    TreeNode* prev = nullptr;

    void inOrder(TreeNode* root) {
        if (!root) return;

        inOrder(root->left);

        if (prev != nullptr) {
            minDiff = min(minDiff, root->val - prev->val);
        }
        prev = root;

        inOrder(root->right);
    }

public:
    int minDiffInBST(TreeNode* root) {
        inOrder(root);
        return minDiff;
    }
};