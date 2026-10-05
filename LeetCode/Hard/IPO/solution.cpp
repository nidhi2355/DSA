class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n= profits.size();

        vector<pair<int, int>> c;
        for(int i=0; i<n; i++){
            c.push_back({capital[i], i});
        }

        sort(c.begin(), c.end());

        priority_queue<int> pq;
        int i=0, curr= w;

        while(k--){
            while(i<n and c[i].first <= curr){
                pq.push(profits[c[i].second]);
                i++;
            }

            if(pq.empty()) return curr;

            curr+= pq.top();

            pq.pop();
        }

        return curr;
    }
};