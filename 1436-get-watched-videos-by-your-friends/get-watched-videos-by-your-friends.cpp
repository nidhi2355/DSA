class Solution {
public:

    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n= friends.size();

        vector<int> lvl(n, 1e8);
        lvl[id]=0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, id});

        while(!pq.empty()){
            int l= pq.top().first;
            int person= pq.top().second;

            pq.pop();

            for(auto it: friends[person]){
                if(lvl[it]> l+1){
                    lvl[it]= l+1;
                    pq.push({lvl[it], it});
                }
            }
        }

        vector<int> f;
        for(int i=0; i<n; i++){
            if(lvl[i]==level) f.push_back(i);
        }

        unordered_map<string, int> mpp;

        for(auto &it: f){
            for(auto el: watchedVideos[it]){
                mpp[el]++;
            }
        }

        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> videos;

        for(auto &it: mpp){
            videos.push({it.second, it.first});
        }

        vector<string> res;

        while(!videos.empty()){
            res.push_back(videos.top().second);
            videos.pop();
        }

        return res;
    }
};