#include<bits/stdc++.h>

class Solution {
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
        int n= original.size();
        long long low= bounds[0][0], high= bounds[0][1];
        long long diff= 0;

        for(int i=1; i<n; i++){
            diff+= (long long)original[i]- original[i-1];
            long long r= (long long)bounds[i][0] - diff;
            low = max(low, r);
            r= (long long)bounds[i][1] - diff;
            high = min(high, r);
        }

        return max(0LL, high-low+1);
    }
};