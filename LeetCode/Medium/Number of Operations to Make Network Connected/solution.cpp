class DSU{
    vector<int> parent, size;

public:
    DSU(int n){
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

    void findunion(int p, int q){
        int ulp_p= findParent(p);
        int ulp_q= findParent(q);

        if(ulp_p == ulp_q) return;

        if(size[ulp_p]> size[ulp_q]){
            parent[ulp_q]= ulp_p;
            size[ulp_p]+= size[ulp_q];
        }
        else{
            parent[ulp_p]= ulp_q;
            size[ulp_q]+= size[ulp_p];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()< n-1) return -1;

        DSU d(n);

        for(auto &it: connections){
            d.findunion(it[0], it[1]);
        }

        unordered_set<int> components;

        for(int i=0; i<n; i++){
            components.insert(d.findParent(i));
        }

        return components.size()-1;
    }
};