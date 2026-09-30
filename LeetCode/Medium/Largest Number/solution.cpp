class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n= nums.size();
        vector<string> temp(n);

        for(int i=0; i<n; i++){
            temp[i]= to_string(nums[i]);
        }

        sort(temp.begin(), temp.end(), [](string &a, string &b){return a+b> b+a;});

        if(temp[0][0]=='0') return "0";

        string res="";

        for(int i=0; i<n; i++){
            res+= temp[i];
        }

        return res;
    }
};