from ast import List


class Solution:
    def Helper(self, find, potions: List[int]) -> int:
        st = 0
        ed = len(potions) - 1

        index = len(potions)
        while (st <= ed):
            mid = st + int((ed - st) / 2)

            if  potions[mid] >= find:
                index = mid
                ed = mid - 1
            
            elif potions[mid] < find:
                st = mid + 1
        
        return len(potions) - index



    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        potions.sort()
        answer = []
        for num in spells:
            answer.append(self.Helper(success / num,potions))
        
        return answer
