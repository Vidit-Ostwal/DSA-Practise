from ast import List

class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        Final_List = []

        j = n

        for i in range(n):
            Final_List.append(nums[i])
            Final_List.append(nums[j])
            j = j + 1
        
        return Final_List