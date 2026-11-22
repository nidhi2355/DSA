class Solution(object):
    def transformString(self, chars, ind):
        if ind == len(chars):
            self.st.add("".join(chars))
            return
        
        if chars[ind].isdigit():
            self.transformString(chars, ind + 1)
        else:
            chars[ind] = chars[ind].lower()
            self.transformString(chars, ind + 1)
            
            chars[ind] = chars[ind].upper()
            self.transformString(chars, ind + 1)

    def letterCasePermutation(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        self.st = set()
        self.transformString(list(s), 0)
        return list(self.st)