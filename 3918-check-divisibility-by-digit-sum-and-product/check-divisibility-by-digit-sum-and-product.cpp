class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0, prod=1;
        int temp=n;

        while(n){
            sum+= n%10;
            prod*= n%10;

            n/=10;
        }

        sum+= prod;

        return (temp%sum == 0);
    }
};