class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string res= "";
        if(!num or !sum) return res;

        if(sum> 9*num) return "";

        res.resize(num);

        for(int i=0; i<num; i++){
            if(sum>=9){
                res[i]= '9';
                sum-=9;
            }
            else{
                res[i]= '0'+ sum;
                sum=0;
            }
        }

        return res;
    }
};