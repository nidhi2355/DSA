class Solution {
public:
    int maximumGap(string skill, string station) {
        int n= skill.size(), m= station.size();

        vector<int> left(n), right(n);
        int ind=0;

        for(int i=0; i<n; i++){
            while(station[ind]!= skill[i]) ind++;
            left[i]= ind;
            ind++;
        }

        ind= m-1;

        for(int i= n-1; i>=0 ; i--){
            while(station[ind]!= skill[i]) ind--;
            right[i]= ind;
            ind--;
        }

        int ans= 0;

        for(int i=0; i<n-1; i++){
            ans= max(ans, right[i+1]- left[i]);
        }

        return ans;
    }
};