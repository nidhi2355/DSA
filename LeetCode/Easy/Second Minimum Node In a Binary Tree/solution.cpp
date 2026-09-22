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
    int findSecondMinimumValue(TreeNode* root) {
        if(!root or !root->left) return -1;

        unordered_set<int> s;

        stack<TreeNode*> st;
        TreeNode* curr= root;

        while(!st.empty() or curr){
            if(curr){
                st.push(curr);
                curr= curr->left;
            }
            else{
                curr= st.top();
                st.pop();
                s.insert(curr->val);
                curr= curr->right;
            }
        }

        if(s.size()==1) return -1;
        vector<int> res(s.begin(), s.end());
        sort(res.begin(), res.end());
        return res[1];
    }
};