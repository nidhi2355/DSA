from collections import Counter
class Solution:
    def countFreq(self, arr):
        #code here
        mpp= Counter(arr)
        res= []
        
        for val, cnt in mpp.items():
            temp= [val, cnt]
            res.append(temp)
            
        return res