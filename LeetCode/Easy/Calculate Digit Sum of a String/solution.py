class Solution(object):
    def digitSum(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: str
        """

        res=s

        while len(res)>k:
            temp=""
            for i in range(0, len(res), k):
                rem= len(res)-i
                sumofdigits=0
                for j in range(0, min(rem, k)):
                    sumofdigits+=int(res[i+j])

                temp+= str(sumofdigits)

            res= temp

        return res