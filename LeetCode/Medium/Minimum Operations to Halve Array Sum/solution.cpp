class Solution {
public:
    int halveArray(vector<int>& nums) {
        double sum=0;
        priority_queue<double> pq;

        for(int i=0; i<nums.size(); i++){
            sum+= (double) nums[i];
            pq.push((double) nums[i]);
        }
        int ans=0;

        double target= sum/2.0;

        while(sum> target){
            double curr= pq.top();
            pq.pop();

            curr/=2;

            sum-= curr;

            pq.push(curr);
            ans++;
        }

        return ans;
    }
};