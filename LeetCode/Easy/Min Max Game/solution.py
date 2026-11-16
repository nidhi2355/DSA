class Solution(object):
    def minMaxGame(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n= len(nums)

        while n>1:
            n/=2

            for i in range(0, n):
                if i%2 == 0:
                    nums[i]= min(nums[2*i], nums[2*i+1])
                else:
                    nums[i]= max(nums[2*i], nums[2*i+1])

        return nums[0]