class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int freq[10]= {0};

        for(int &d: digits){
            freq[d]++;
        }

        vector<int> res;

        for(int i=100; i<=999; i+=2){
            int cnt[10]={0};

            cnt[i/100]++;
            cnt[(i/10)%10]++;
            cnt[i%10]++;

            bool flag= true;

            for(int j=0; j<10; j++){
                if(cnt[j] > freq[j]){
                    flag= false;
                    break;
                }
            }

            if(flag){
                res.push_back(i);
            }
        }

        return res;
    }
};