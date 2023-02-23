from ast import List


class Solution:
    def findMaximizedCapital(self, k: int, w: int, profits: List[int], capital: List[int]) -> int:
        vect = []

        for index in range(len(profits)):
            vect.append([capital[index],profits[index]])
        
        vect.sort()

        index = 0
        maximisecapital = []
        while k:
            while index < len(vect) and vect[index][0] <= w:
                heapq.heappush(maximisecapital,-vect[index][1])
                index = index + 1
            
            if not maximisecapital:
                break
            
            w -= heapq.heappop(maximisecapital)
            k -= 1
        return w
