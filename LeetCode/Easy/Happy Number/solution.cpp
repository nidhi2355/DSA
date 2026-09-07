class Solution {
public:
    bool isHappy(int n) {
        int num= n;
        while(num){
            int temp= num;
            int res=0;
            while(temp){
                res+= (temp%10)*(temp%10);
                temp/=10;
            }
            if(res==1) return true;
            num=res;
            if(num==4) return false;
        }
        return false;
    }
};