from collections import Counter

class Solution(object):
    def rearrangeArray(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        mpp = Counter(nums)
        res = []
        
        while mpp:
            unique_keys = sorted(mpp.keys())
            res.extend(unique_keys)
            
            for val in unique_keys:
                mpp[val] -= 1
                if mpp[val] == 0:
                    del mpp[val]
                    
        return res