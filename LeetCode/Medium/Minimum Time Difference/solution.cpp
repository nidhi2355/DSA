class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n= timePoints.size();

        vector<int> temp(n);
        for(int i=0; i<n; i++){
            int time= stoi(timePoints[i].substr(0, 2))*60;
            time+= stoi(timePoints[i].substr(3));

            temp[i]= time;
        }

        sort(temp.begin(), temp.end());

        int ans=INT_MAX;

        for(int i=0; i<n; i++){
            int curr= abs(temp[i]- temp[(i+1)%n]);
            curr= min(curr, 1440-curr);
            ans= min(ans, curr);
        }

        return ans;
    }
};