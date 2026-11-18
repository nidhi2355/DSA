class Solution(object):
    def minChanges(self, s):
        """
        :type s: str
        :rtype: int
        """
        n= len(s)
        ans=0
        for i in range(1, n, 2):
            if s[i]!= s[i-1]:
                ans+=1

        return ans