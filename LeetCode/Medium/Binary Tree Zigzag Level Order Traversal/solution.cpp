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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;

        queue<TreeNode*> q;
        bool flag= false;

        q.push(root);

        while(!q.empty()){
            int s= q.size();
            TreeNode* curr;
            vector<int> temp(s);

            for(int i=0; i<s; i++){
                curr= q.front();
                q.pop();

                temp[i]= curr->val;

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }

            if(flag) reverse(temp.begin(), temp.end());

            ans.push_back(temp);
            flag= !flag;
        }

        return ans;
    }
};