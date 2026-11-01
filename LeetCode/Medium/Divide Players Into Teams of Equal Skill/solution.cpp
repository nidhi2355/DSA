class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n= skill.size();

        sort(skill.begin(), skill.end());

        int s= skill[0]+ skill[n-1];
        long long ans=skill[0]*skill[n-1];

        int i=1, j= n-2;

        while(i<j){
            if(s != skill[i]+ skill[j]){
                return -1;
            }
            ans+= 1LL*skill[i]*skill[j];
            i++;
            j--;
        }

        return ans;
    }
};