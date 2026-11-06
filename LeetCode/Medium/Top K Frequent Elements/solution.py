class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        mpp= Counter(nums)
        res= []
        ans=[]

        for val, cnt in mpp.items():
            temp= [cnt, val]
            res.append(temp)

        res.sort()
        for i in range(-1, -k-1, -1):
            ans.append(res[i][1])

        return ans