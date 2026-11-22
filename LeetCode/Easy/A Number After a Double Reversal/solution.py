class Solution(object):
    def isSameAfterReversals(self, num):
        """
        :type num: int
        :rtype: bool
        """
        
        temp= num
        rev1=0

        while num:
            rev1*=10
            rev1+= num%10
            num//=10

        rev2=0
        while rev1:
            rev2*=10
            rev2+= rev1%10
            rev1//=10

        return temp==rev2