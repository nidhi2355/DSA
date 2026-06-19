/*
  Problem: https://leetcode.com/problems/count-subarrays-with-score-less-than-k/description/

  The score of an array is defined as the product of its sum and its length.

  For example, the score of [1, 2, 3, 4, 5] is (1 + 2 + 3 + 4 + 5) * 5 = 75.
  Given a positive integer array nums and an integer k, return the number of non-empty subarrays of nums whose score is strictly less than k.

  A subarray is a contiguous sequence of elements within an array.
*/
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n= nums.size();
        long long ans=0, sum=0;
        int left=0;
        for(int right=0;right<n;right++){
            sum+= nums[right];
            while(left<right and (1LL*sum*(right-left+1)>=k)){
                sum-= nums[left];
                left++;
            }
            if(sum<k) ans+= right-left+1;
        }
        return ans;
    }
};
