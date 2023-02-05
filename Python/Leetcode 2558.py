import math
from queue import PriorityQueue

class Solution:
    def pickGifts(self, gifts: List[int], k: int) -> int:
        
        pq = PriorityQueue()
        
        for number in gifts:
            pq.put(-1 * number)
        
        while k:
            k = k - 1
            
            top  = -1*int(pq.get())
            print(top , math.sqrt(top))
            pq.put(-1*math.sqrt(top))
            
        
        answer = 0
        print(pq.qsize())
        while not pq.empty():
            answer = answer + -1*int(pq.get())
            
        return answer
        
        