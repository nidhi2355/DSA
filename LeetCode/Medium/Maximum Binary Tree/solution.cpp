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
unordered_map<int,int> mpp;
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n= nums.size();
        int maxnum= -1;

        for(int i=0; i<n;i++){
            mpp[nums[i]]= i;
            maxnum= max(maxnum, nums[i]);
        }

        int rootind=mpp[maxnum];

        TreeNode* root= new TreeNode(maxnum);

        root->left= buildTree(nums, 0, rootind-1);
        root->right= buildTree(nums, rootind+1, n-1);

        return root;

    }

    TreeNode* buildTree(vector<int> &nums, int l, int r){
        if(l>r) return nullptr;

        int maxnum= -1;

        for(int i= l; i<= r; i++){
            maxnum= max(maxnum, nums[i]);
        }

        int rootind= mpp[maxnum];

        TreeNode* root= new TreeNode(maxnum);

        root->left= buildTree(nums, l, rootind-1);
        root->right= buildTree(nums, rootind+1, r);

        return root;
    }
};