class Solution(object):
    def triangularSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res= nums

        while len(res)>1:
            temp=[]

            for i in range(0, len(res)-1):
                ele= (res[i]+ res[i+1])%10
                temp.append(ele)

            res= temp

        return res[0]