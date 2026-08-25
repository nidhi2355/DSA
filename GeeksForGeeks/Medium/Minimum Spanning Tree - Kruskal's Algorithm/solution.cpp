class DisjointSet{
  vector<int> rank, parent, size;
  
  public:
    DisjointSet(int n){
        rank.resize(n, 0);
        parent.resize(n);
        size.resize(n);
        
        for(int i=0; i<n; i++){
            parent[i]= i;
            size[i]=1;
        }
    }
    
    int findParent(int node){
        if(parent[node]==node) return node;
        return parent[node]= findParent(parent[node]);
    }
    
    void unionByRank(int p, int q){
        int up= findParent(p);
        int uq= findParent(q);
        
        if(up==uq) return;
        
        if(up> uq){
            parent[uq]= up;
        }
        else if(uq> up){
            parent[up]= uq;
        }
        else{
            parent[uq]= up;
            rank[up]++;
        }
    }
    
    void unionBySize(int p, int q){
        int up= findParent(p);
        int uq= findParent(q);
        
        if(up==uq) return;
        
        if(up> uq){
            parent[uq]= up;
            size[up]+= size[uq];
        }
        else{
            parent[up]= uq;
            size[uq]+= size[up];
        }
    }
};

class Solution {
  public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        for(auto &it: edges){
            reverse(it.begin(), it.end());
            swap(it[1], it[2]);
        }
        
        // edges-> {w, u, v}
        
        sort(edges.begin(), edges.end());
        
        DisjointSet ds(V);
        
        int cost=0;
        
        for (auto &it: edges){
            int w= it[0], u= it[1], v= it[2];
            
            if(ds.findParent(u)!= ds.findParent(v)){
                cost+= w;
                ds.unionBySize(u, v);
            }
        }
        
        return cost;
    }
};