class Solution {
public:
    long long countCommas(long long n) {
        long long cnt=0;

        if(n<=999) return 0;

        long long div= 999999999999999;
        long long comma= 5;

        while(div>= 999){
            if(n>= div){
                cnt+= comma*(n-div);
                n=div;
            }

            comma--;

            div/=1000;
        }

        return cnt;
    }
};