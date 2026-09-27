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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent;
        parent[root]= nullptr;
        TreeNode* startnode= nullptr;
        TreeNode* curr;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            curr= q.front();
            q.pop();

            if(curr->val == start) startnode= curr;

            if(curr->left){
                parent[curr->left]= curr;
                q.push(curr->left);
            }
            if(curr->right){
                parent[curr->right]= curr;
                q.push(curr->right);
            }
        }

        q = queue<TreeNode*>();
        unordered_set<TreeNode*> st;
        st.insert(startnode);

        q.push(startnode);
        int ans=0;

        while(!q.empty()){
            int s= q.size();

            for(int i=0; i<s; i++){
                curr= q.front();
                q.pop();

                if(curr->left and st.find(curr->left)== st.end()){
                    q.push(curr->left);
                    st.insert(curr->left);
                }

                if(curr->right and st.find(curr->right) == st.end()){
                    q.push(curr->right);
                    st.insert(curr->right);
                }

                if(parent[curr] and st.find(parent[curr])== st.end()){
                    q.push(parent[curr]);
                    st.insert(parent[curr]);
                }
            }

            if(!q.empty()) ans++;
        }

        return ans;
    }
};