from ast import List


class Solution:
    # Functional Binary Search
    def Helper(self,weight: int, weights: List[int]) -> int:
        days_count = 1

        index = 0
        temp_weight = 0
        while index < len(weights):
            temp_weight = temp_weight + weights[index]

            if temp_weight > weight:
                temp_weight = weights[index]
                days_count = days_count + 1
            index = index + 1
        
        return days_count

    def shipWithinDays(self, weights: List[int], days: int) -> int:

        # mini = 1000000000
        maxi = -1

        for weight in weights:
            maxi = max(maxi,weight)
            # mini = min(mini,weight)
        
        answer = 100000000

        st = maxi
        ed = 10000000
        while (st <= ed):

            mid = st + (int)((ed - st) / 2)

            required_days = self.Helper(mid,weights)

            if (required_days > days):
                st =  mid + 1
            else:
                answer = mid
                ed = mid - 1
        
        return answer