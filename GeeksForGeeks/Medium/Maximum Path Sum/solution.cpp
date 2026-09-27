/* Structure of binary tree node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
  int maxsum=INT_MIN;
    int findMaxSum(Node *root) {
        findMaxPathSum(root);
        return maxsum;
    }
    
    int findMaxPathSum(Node* root){
        if(!root) return 0;
        
        int leftTree = findMaxPathSum(root->left);
        int rightTree= findMaxPathSum(root->right);
        
        maxsum= max(maxsum, leftTree+ rightTree+ root->data);
        
        return max({0, leftTree+root->data, rightTree+root->data});
    }
};