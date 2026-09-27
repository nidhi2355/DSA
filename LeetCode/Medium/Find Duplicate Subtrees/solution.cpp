class Solution {
    unordered_map<string, int> subtrees;
    vector<TreeNode*> duplicates;

    string serialize(TreeNode* root) {
        if (!root) return "#";

        string s = to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);

        if (++subtrees[s] == 2) {
            duplicates.push_back(root);
        }

        return s;
    }

public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        subtrees.clear();
        duplicates.clear();
        serialize(root);
        return duplicates;
    }
};