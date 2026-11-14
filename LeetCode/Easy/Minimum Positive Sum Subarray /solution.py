class Solution(object):
    def minimumSumSubarray(self, nums, l, r):
        """
        :type nums: List[int]
        :type l: int
        :type r: int
        :rtype: int
        """

        ans= 10000000
        prefix= [0]*(len(nums)+1)

        for i in range (0, len(nums)):
            prefix[i+1]= prefix[i]+ nums[i]

        for length in range (l, r+1):
            for i in range (0, len(nums)-length+1):
                temp= prefix[i+length]- prefix[i]
                if temp>0:
                    ans= min(ans, temp)

        
        if ans == 10000000:
            return -1

        return ans