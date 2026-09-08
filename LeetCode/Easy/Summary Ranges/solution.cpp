class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int ind=0, n= nums.size();

        while(ind<n){
            int start= nums[ind];

            int right= ind+1;

            while(right<n and nums[right]== nums[right-1]+1) right++;

            int end= nums[right-1];

            if(start==end) {
                ans.push_back(to_string(start));
            }

            else{
                string temp;
                temp+=to_string(start);
                temp+="->";
                temp+=to_string(end);

                ans.push_back(temp);
            }

            ind= right;
        }

        return ans;
    }
};