class Solution {
public:
int n;
    int sortableIntegers(vector<int>& nums) {
        n= nums.size();
        vector<int> temp= nums;
        sort(temp.begin(), temp.end());

        vector<int> div;
        for(int i=1; i*i<=n; i++){
            if (n % i == 0) {
                div.push_back(i);
                if (i * i != n) {
                    div.push_back(n / i);
                }
            }
        }

        int ans=0;

        for(auto &it: div){
            if(isValid(it, nums, temp)) ans+=it;
        }

        return ans;
    }

    bool isValid(int k, vector<int> &nums, vector<int> &temp){
        for(int i=0; i<n; i+=k){
            if(k==1){
                if(nums[i]!= temp[i]) return false;
                continue;
            }

            int drops=0, drop_ind = -1;

            for(int j=0; j<k; j++){
                int curr= nums[i+j];
                int next= nums[i+ (j+1)%k];

                if(curr> next){
                    drops++;
                    drop_ind= j;
                }

                if(drops>1) return false;
            }

            int offset= (drops==0)? 0: (drop_ind+1)%k;

            for(int j=0; j<k; j++){
                if(nums[i+(j+offset)%k] != temp[i+j]) return false;
            }
        }

        return true;
    }
};