class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>> > mpp;
    vector<string> res;

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto it: tickets){
            mpp[it[0]].push(it[1]);
        }
        dfs("JFK");
        reverse(res.begin(), res.end());
        return res;
    }

private:
    void dfs(string s){
        auto &pq= mpp[s];
        while(!pq.empty()){
            string curr= pq.top();
            pq.pop();
            dfs(curr);
        }
        res.push_back(s);
    }
};