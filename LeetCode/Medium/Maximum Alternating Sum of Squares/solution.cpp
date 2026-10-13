class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        priority_queue<int> pq;
        int n= nums.size();

        for(int i=0; i<n; i++){
            pq.push(abs(nums[i]));
        }

        long long ans=0;

        for(int i=0; i<n; i+=2){
            nums[i]= pq.top();
            pq.pop();
        }

        for(int i=1; i<n; i+=2){
            nums[i]= pq.top();
            pq.pop();
        }

        for(int i=0; i<n; i++){
            if(i%2 ==0){
                ans+= 1LL*nums[i]*nums[i];
            }
            else{
                ans-= 1LL*nums[i]*nums[i];
            }
        }

        return ans;
    }
};