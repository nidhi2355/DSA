/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        int n= grid.size();
        return constructTree(grid, 0, 0, n);
    }

private:
    Node* constructTree(vector<vector<int>> &grid, int row, int col, int len){
        if(isSame(grid, row, col, len)) {
            return new Node(grid[row][col]==1, true);
        }

        Node* newnode= new Node(true, false);
        newnode->topLeft= constructTree(grid, row, col, len/2);
        newnode->topRight= constructTree(grid, row, col+(len/2), len/2);
        newnode->bottomLeft= constructTree(grid, row+(len/2), col, len/2);
        newnode->bottomRight= constructTree(grid, row+(len/2), col+(len/2), len/2);

        return newnode;
    }

    bool isSame(vector<vector<int>> &grid, int row, int col, int len){
        int val= grid[row][col];
        for(int i= row; i<row+len; i++){
            for(int j= col; j< col+len; j++){
                if(grid[i][j]!= val) return false;
            }
        }

        return true;
    }
};