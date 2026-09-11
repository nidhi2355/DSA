class Solution {
public:
    int findComplement(int num) {
        long long res=0;
        long long mul=1;

        while(num){
            if(num%2==0){
                res+= mul;
            }

            mul*=2;
            num/=2;
        }

        return (int) res;
    }
};