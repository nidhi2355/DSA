class Solution {
public:
vector<int> count;
vector<int> ans;
int n;

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        this->n= n;
        vector<vector<int>> adj(n);

        for(auto &it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        count.resize(n);
        ans.resize(n);

        countNodes(0, adj, -1);

        computeAns(0, adj, -1);

        return ans;
    }

    void countNodes(int node, vector<vector<int>> &adj, int parent){
        count[node]= 1;

        for(auto &it: adj[node]){
            if(it==parent) continue;
            countNodes(it, adj,node);
            count[node]+= count[it];
            ans[node]+= count[it]+ ans[it];
        }

    }

    void computeAns(int node, vector<vector<int>> &adj, int parent){
        for(auto &it: adj[node]){
            if(it==parent) continue;

            ans[it]= ans[node] - count[it]+ (n- count[it]);

            computeAns(it, adj, node);
        }
    }
};