class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        unordered_set<char> st;
        for(auto it: words){
            for(auto el: it) st.insert(el);
        }
        int elements= st.size();
        unordered_map<char, vector<char>> mpp;
        int n= words.size();
        for(int i=0;i<n-1;i++){
            if(words[i].size()> words[i+1].size() and words[i].substr(0, words[i+1].size()) == words[i+1]) 
                return "";
            int s= min(words[i].size(), words[i+1].size());
            for(int j=0;j<s;j++){
                if(words[i][j]!= words[i+1][j]){
                    mpp[words[i][j]].push_back(words[i+1][j]);
                    break;
                }
            }
        }
        string ans="";
        unordered_map<char, int> indegree;
        for(auto it: st) indegree[it]=0;
        for(auto it: mpp){
            for(auto el: it.second){
                indegree[el]++;
            }
        }
        queue<char> q;
        for(auto it: indegree){
            if(it.second==0) q.push(it.first);
        }
        while(!q.empty()){
            char c= q.front();
            q.pop();
            ans.push_back(c);
            for(auto it: mpp[c]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        if(ans.size()==elements) return ans;
        return "";
    }
};