using p= tuple<int, int, int>;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1= nums1.size(), n2= nums2.size();
        int ind= min(n1, k);

        priority_queue<p, vector<p> , greater<p>> minpq;

        for(int i=0; i<ind; i++){
            minpq.emplace(nums1[i]+ nums2[0], i, 0);
        }

        vector<vector<int>> res;

        while(k-- and !minpq.empty()){
            auto [sum, i, j]= minpq.top();
            minpq.pop();

            res.push_back({nums1[i], nums2[j]});

            if(j< n2-1) minpq.emplace(nums1[i]+nums2[j+1], i, j+1);
        }

        return res;
    }
};