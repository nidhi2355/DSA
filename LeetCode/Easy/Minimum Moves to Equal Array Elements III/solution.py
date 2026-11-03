class Solution(object):
    def minMoves(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        maxe= nums[0]
        for num in nums:
            maxe= max(maxe, num)

        op=0
        for num in nums:
            op= op+ maxe-num

        return op
        