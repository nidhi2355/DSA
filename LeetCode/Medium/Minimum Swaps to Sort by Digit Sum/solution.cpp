class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n= nums.size();

        vector<pair<pair<int, int>, int>> arr(n);
        for(int i=0; i<n; i++){
            int sum=0, t= nums[i];
            while(t){
                sum+= t%10;
                t/=10;
            }

            arr[i]= {{sum, nums[i]}, i};
        }

        sort(arr.begin(), arr.end());
        int ans=0;

        vector<bool> vis(n, false);

        for(int i=0; i<n; i++){
            if(vis[i] or arr[i].second==i) continue;
            int curr= i;
            while(!vis[curr]){
                vis[curr]= true;
                curr= arr[curr].second;
                ans++;
            }

            ans--;
        }

        return ans;
    }
};