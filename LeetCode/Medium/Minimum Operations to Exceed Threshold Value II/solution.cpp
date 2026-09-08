class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n= nums.size();

        if(n< 2) return 0;

        int ans=0;

        priority_queue<long long, vector<long long>, greater<long long>> pq;

        for(int &i: nums) pq.push((long long) i);

        while(pq.size()>1){
            if(pq.top() >= k) return ans;

            long long x= pq.top();
            pq.pop();

            long long y= pq.top();
            pq.pop();

            pq.push(2*x+ y);
            ans++;
        }

        return ans;
    }
};