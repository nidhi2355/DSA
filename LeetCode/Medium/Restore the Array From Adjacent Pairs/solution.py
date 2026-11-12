from collections import defaultdict

class Solution(object):
    def restoreArray(self, adjacentPairs):
        """
        :type adjacentPairs: List[List[int]]
        :rtype: List[int]
        """
        graph = defaultdict(list)
        for u, v in adjacentPairs:
            graph[u].append(v)
            graph[v].append(u)
            
        firstelement = 0
        for val, neighbours in graph.items():
            if len(neighbours) == 1:
                firstelement = val
                break
                
        n = len(adjacentPairs)
        res = [firstelement] * (n + 1)
        
        res[1] = graph[firstelement][0]
        
        ind = 2
        while ind <= n:
            curr = res[ind - 1]
            prev = res[ind - 2]
            
            for neighbour in graph[curr]:
                if neighbour != prev:
                    res[ind] = neighbour
                    break
            ind += 1
            
        return res