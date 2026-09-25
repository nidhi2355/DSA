class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> vis(numCourses);
        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
            vis[it[0]]++;
        }        
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(vis[i]==0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int course= q.front();
            q.pop();
            ans.push_back(course);
            for(auto it: adj[course]){
                vis[it]--;
                if(vis[it]==0) q.push(it);
            }
        }
        if(ans.size()==numCourses) return ans;
        return {};
    }
};