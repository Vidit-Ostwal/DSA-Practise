class Solution:
    def totalFruit(self, fruits: List[int]) -> int:

        st = 0
        ed = 0
        answer = 0

        temp_dict = dict()

        while ed < len(fruits):
            temp_dict[fruits[ed]] = temp_dict.get(fruits[ed],0) + 1

            # print("ED", ed)
            while len(temp_dict) > 2:
                # print(st)
                temp_dict[fruits[st]] = temp_dict.get(fruits[st]) - 1

                if temp_dict[fruits[st]] == 0:
                    del temp_dict[fruits[st]]
                st = st + 1
                
            answer = max(answer,ed - st + 1)
            ed = ed + 1

        return answer   

