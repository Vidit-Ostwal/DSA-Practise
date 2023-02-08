class Solution:
    def jump(self, nums: List[int]) -> int:
        Required_Jumps = [0] * len(nums)
        # Required_Jumps[0] = 1
        # print(Required_Jumps)

        for index in range(len(nums) - 2,-1,-1):
            
            max_jumps = nums[index]
            temp_jumps = 1000000000

            for jump in range(1,max_jumps+1,1):
                if index + jump < len(nums):
                    temp_jumps = min(temp_jumps,Required_Jumps[index + jump])
            
            Required_Jumps[index] = temp_jumps + 1

        # print(Required_Jumps)
        return Required_Jumps[0]
