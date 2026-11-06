class Solution(object):
    def maxFrequencyElements(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        mpp= Counter(nums)

        max_freq=0
        cnt=0

        for val, count in mpp.items():
            if count>max_freq:
                max_freq= count
                cnt=1

            elif count == max_freq:
                cnt= cnt+1

        return cnt*max_freq