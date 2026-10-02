class Solution {
public:
    int minSwaps(string s) {
        int n= s.size();
        int cnt=0;
        int swaps=0;

        for(int i=0; i<n; i++){
            if(s[i]==']') {
                if(cnt ==0){
                    swaps++;
                    cnt++;
                }
                else{
                    cnt--;
                }
            }
            else{
                cnt++;
            }
        }

        return swaps;
    }
};