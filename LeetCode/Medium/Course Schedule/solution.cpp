class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> vis(numCourses, 0);
        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
            vis[it[0]]++;
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(vis[i]==0) q.push(i);
        }
        if(q.empty()) return false;

        int cnt=0;

        while(!q.empty()){
            int curr= q.front();
            cnt++;
            q.pop();
            for(auto it: adj[curr]){
                vis[it]--;
                if(vis[it]==0) q.push(it);
            }
        }

        return cnt==numCourses;
    }
};