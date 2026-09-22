class NeighborSum {
public:
    map<int, pair<int, int>> mpp;
    map<pair<int, int>, int> val;
    int n;

    NeighborSum(vector<vector<int>>& grid) {
        n= grid.size();

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                mpp[grid[i][j]]= {i, j};
                val[{i, j}]= grid[i][j];
            }
        }
    }
    
    int adjacentSum(int value) {
        pair<int, int> rc= mpp[value];
        int row= rc.first, col= rc.second;

        int sum=0;
        if(row>0) sum+= val[{row-1, col}];
        if(row<n-1) sum+= val[{row+1, col}];
        if(col>0) sum+= val[{row, col-1}];
        if(col<n-1) sum+= val[{row, col+1}];

        return sum;
    }
    
    int diagonalSum(int value) {
        pair<int, int> rc= mpp[value];
        int row= rc.first, col= rc.second;

        int sum=0;
        if(row>0 and col>0) sum+= val[{row-1, col-1}];
        if(row<n-1 and col>0) sum+= val[{row+1, col-1}];
        if(col<n-1 and row>0) sum+= val[{row-1,col+1}];
        if(col<n-1 and row< n-1) sum+= val[{row+1,col+1}];

        return sum;
    }
};

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */