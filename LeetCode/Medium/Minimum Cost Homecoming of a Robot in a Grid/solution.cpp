class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int ans=0;

        int startrow= startPos[0], startcol= startPos[1], endrow= homePos[0], endcol= homePos[1];

        if(startrow< endrow){
            for(int i= startrow+1; i<= endrow; i++) ans+= rowCosts[i];
        }
        else{
            for(int i= startrow-1; i>= endrow; i--) ans+= rowCosts[i];
        }

        if(startcol<= endcol){
            for(int j= startcol+1; j<= endcol; j++) ans+= colCosts[j];
        }
        else{
            for(int j= startcol-1; j>= endcol; j--) ans+= colCosts[j];
        }

        return ans;
    }
};