class Solution(object):
    def findTheDistanceValue(self, arr1, arr2, d):
        """
        :type arr1: List[int]
        :type arr2: List[int]
        :type d: int
        :rtype: int
        """

        ans=0
        for num in arr1:
            flag= True
            for el in arr2:
                if abs(num-el)<=d:
                    flag= False
                    break

            if flag==True:
                ans= ans+1
        
        return ans