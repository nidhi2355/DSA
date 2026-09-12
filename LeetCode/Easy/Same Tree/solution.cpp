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
    bool isSameTree(TreeNode* p, TreeNode* qu) {
        if(!p and !qu) return true;
        if(!p or !qu) return false;

        queue<pair<TreeNode*, TreeNode*>> q;

        q.push({p, qu});

        while(!q.empty()){
            TreeNode* t1= q.front().first;
            TreeNode* t2= q.front().second;

            q.pop();

            if(!t1 and !t2) continue;
            if(!t1 or !t2) return false;

            if(t1->val != t2->val) return false;

            q.push({t1->left, t2->left});
            q.push({t1->right, t2->right});
        }

        return true;
    }
};