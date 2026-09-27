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
    unordered_map<int, int> mpp;
    int maxf= 0;

    vector<int> findFrequentTreeSum(TreeNode* root) {
        if(!root->left and !root->right) return {root->val};

        dfs(root);

        priority_queue<pair<int, int>> pq;

        vector<int> ans;

        for(auto &it: mpp){
            if(it.second== maxf){
                ans.push_back(it.first);
            }
        }

        return ans;
    }

    int dfs(TreeNode* root){
        if(!root) return 0;

        int left= dfs(root->left);
        int right= dfs(root->right);

        mpp[left+right+root->val]++;
        maxf= max(maxf, mpp[left+right+root->val]);

        return left+right+root->val;
    }
};