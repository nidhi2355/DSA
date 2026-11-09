class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        xor1=0
        xor2=0

        for i in range (0, len(nums)):
            xor1= xor1^nums[i]
            xor2 = xor2^(i+1)

        return xor1^xor2
        