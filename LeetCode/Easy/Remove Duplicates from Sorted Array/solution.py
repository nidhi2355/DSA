class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left=1
        for i in range(1, len(nums)):
            if nums[i]!= nums[i-1]:
                nums[left]= nums[i]
                left= left+1

        return left