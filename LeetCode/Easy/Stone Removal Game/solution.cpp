class Solution {
public:
    bool canAliceWin(int n) {
        int stones=10;
        bool Alice= true;

        while(stones){
            if(n< stones) {
                if(Alice) return false;
                return true;
            }

            n-= stones;
            stones--;
            Alice= !Alice;
        }

        return !Alice;
    }
};