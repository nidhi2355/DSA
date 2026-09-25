class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> st(bank.begin(), bank.end());
        int steps=0;
        if(!st.count(endGene)) return -1;
        queue<string> q;
        q.push({startGene});
        vector<char> genes={'A','C','G','T'};
        while(!q.empty()){
            int s= q.size();
            while(s--){
                string curr= q.front();
                q.pop();
                if(curr== endGene) return steps;
                for(int i=0;i<8;i++){
                    char c= curr[i];
                    for(auto it: genes){
                        curr[i]=it;
                        if(st.find(curr)!= st.end()){
                            q.push(curr);
                            st.erase(curr);
                        }
                    }
                    curr[i]=c;
                }
            }
            steps++;
        }
        return -1;
    }
};