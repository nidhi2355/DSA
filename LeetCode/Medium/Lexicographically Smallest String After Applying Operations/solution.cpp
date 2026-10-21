class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        int n= s.size();

        string ans= s;
        queue<string> q;
        q.push(s);
        unordered_set<string> vis;
        vis.insert(s);

        while(!q.empty()){
            string curr= q.front();
            q.pop();

            ans= min(ans, curr);

            string temp= curr;
            for(int i=1; i<n; i+=2){
                temp[i]= ((temp[i] - '0' + a) % 10) + '0';
            }

            if(vis.find(temp)== vis.end()){
                vis.insert(temp);
                q.push(temp);
            }

            temp= curr.substr(n-b)+ curr.substr(0, n-b);
            if(vis.find(temp)== vis.end()){
                vis.insert(temp);
                q.push(temp);
            }
        }

        return ans;
    }
};