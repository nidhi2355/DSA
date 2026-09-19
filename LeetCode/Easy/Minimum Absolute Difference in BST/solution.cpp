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
    int getMinimumDifference(TreeNode* root) {
        vector<int> ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            ans.push_back(q.front()->val);
            if(q.front()->left) q.push(q.front()->left);
            if(q.front()->right) q.push(q.front()->right);

            q.pop();
        }

        sort(ans.begin(), ans.end());
        int res= INT_MAX;

        for(int i=0; i<ans.size()-1; i++){
            res= min(res, ans[i+1]-ans[i]);
        }

        return res;
    }
};