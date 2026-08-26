class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st;
        int n= beginWord.size();

        for(auto &it: wordList){
            st.insert(it);
        }

        if(!st.count(endWord)) return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while(!q.empty()){
            string word= q.front().first;
            int steps= q.front().second;

            if(word==endWord) return steps;

            q.pop();

            for(int i=0; i<n; i++){
                char c= word[i];
                
                for(char t= 'a'; t<= 'z'; t++){
                    if(t==c) continue;
                    word[i]= t;
                    if(st.count(word)){
                        q.push({word, steps+1});
                        st.erase(word);
                    }
                }

                word[i]= c;
            }
        }

        return 0;
    }
};