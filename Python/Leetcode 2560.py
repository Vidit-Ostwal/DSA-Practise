class Solution:
    ### Functional Binary Search Problem
    
    def Possible(self, nums: List[int], mid: int, k : int,size : int) -> bool:
        count = 0
        
        # print(mid)
        flag = 0
        index = 0
        while index < size:
            # print(index)
            if (nums[index] <= mid):
                count = count + 1
                index = index + 1
                
            index = index + 1
        
        if (count >= k):
            return True
        return False
            
        
        
    def minCapability(self, nums: List[int], k: int) -> int:
        
        st = min(nums)
        ed = max(nums)
        
        answer = -1
        size = len(nums)
        while (st <= ed):
            
            mid = st + int((ed - st)/ 2)
            
            if self.Possible(nums,mid,k,size):
                answer = mid
                ed = mid - 1
            
            else:
                st = mid + 1
                
            # print(mid , "  " , st , "   ", ed)
        
        return answer