class Solution {
public:
    bool judgeSquareSum(int c) {
        int low=0, high= sqrt(c);

        while(low<= high){

            long long sum= 1LL*low*low+ 1LL*high*high;

            if(sum==c) return true;
            else if(sum > c) high--;
            else low++;
        }

        return false;
    }
};