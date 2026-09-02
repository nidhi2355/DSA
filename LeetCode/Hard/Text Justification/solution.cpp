class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n= words.size();

        vector<int> ind(n);
        vector<pair<int, int>> len;
        int s=0;

        int curr=0, cnt=0, lines=0;

        for(int i=0; i<n; i++){
            if(curr+ words[i].size()+s<= maxWidth){
                curr+= words[i].size();
                cnt++;
                ind[i]= lines; 
                s++;
            }
            else{
                len.push_back({curr, cnt});
                lines++;
                curr= words[i].size();
                cnt=1;
                ind[i]= lines;
                s=1;
            }
        }

        len.push_back({curr, cnt});

        int index=0;

        vector<string> ans;

        for(int i=0; i< len.size(); i++){
            int spaces= maxWidth- len[i].first;
            int gaps= len[i].second-1;

            string temp= "";

            if(i== len.size()-1 or gaps==0){
                for(int j= index; j< index+ len[i].second; j++){
                    temp+= words[j];
                    if(j< index+ len[i].second-1) temp+=' ';
                }

                while(temp.size()< maxWidth) temp+= ' ';
            }

            else{
                int perword= spaces/gaps;
                int extra= spaces%gaps;

                for(int j= index; j< index+ gaps; j++){
                    temp+= words[j];

                    for(int s= 0; s< perword; s++) temp+= ' ';
                    if(extra){
                        temp+= ' ';
                        extra--;
                    }
                }

                temp+= words[index+ gaps];
            }

            ans.push_back(temp); 
            index += len[i].second;
        }

        return ans;
    }
};