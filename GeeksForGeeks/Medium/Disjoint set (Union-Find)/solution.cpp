class Solution {
  public:
    vector<int> parent;
  
    int find(int n){
        if(parent[n]== n) return parent[n];
        
        return parent[n]= find(parent[n]);
    }
    
    void unionfind(int u, int v){
        int parentu= find(u);
        int parentv= find(v);
        
        if(parentu== parentv) return;
        
        parent[parentu]= parentv;
    }
  
  
    vector<int> DSU(int n, vector<vector<int>>& queries) {
        parent.resize(n+1);
        
        for(int i=1; i<=n; i++) parent[i]= i;
        
        vector<int> res;
        
        for(auto & it: queries){
            int op= it[0];
            
            if(op==1){
                int u= it[1], v= it[2];
                unionfind(u, v);
            }
            else{
                res.push_back(find(it[1]));
            }
        }
        
        return res;
    }
};