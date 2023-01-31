from ast import List


class Solution:
    def bestTeamScore(self, scores: List[int], ages: List[int]) -> int:
        temp_list = []
        DP = []
        for i in range(0,len(scores)):
            temp_list.append(list([ages[i],scores[i]]))
            DP.append(0)

        temp_list.sort()
        global_answer = 0
        for i in range(0,len(scores)):

            max_score = temp_list[i][1]
            answer = 0

            for j in range(0,i):
                if (temp_list[j][1] <= max_score):
                    answer = max(answer,DP[j])

            DP[i] = max_score + answer
            global_answer = max(global_answer,DP[i])
        
        #print(temp_list)
        #print(DP)
        return global_answer 