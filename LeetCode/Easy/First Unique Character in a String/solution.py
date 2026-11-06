class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        mpp= Counter(s)
        for i in range(0, len(s)):
            if mpp[s[i]]==1:
                return i

        return -1