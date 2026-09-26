/* Structure of binary tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    Node* lca(Node* root, int n1, int n2) {
        if(!root or root->data==n1 or root->data==n2) return root;
        
        Node* leftree= lca(root->left, n1, n2);
        Node* righttree= lca(root->right, n1, n2);
        
        if(!leftree) return righttree;
        if(!righttree) return leftree;
        
        return root;
    }
};