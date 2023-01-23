from ast import List


class Solution:
    def sortTheStudents(self, score: List[List[int]], k: int) -> List[List[int]]:
        answer = copy.deepcopy(score)
        
        temp_list = []
        
        for i in range(0,len(score)):
            list_pair = []
            list_pair.append(score[i][k])
            list_pair.append(i)
            temp_list.append(list_pair)
        
        temp_list.sort()
        # print(temp_list)
        for i in range(0,len(score)):
            row = temp_list[len(temp_list) -1 - i][1]
            # print(row)
            
            # print(score)
            for j in range(0,len(score[0])):
                answer[i][j] = score[row][j]
            # print(answer)
        
        return answer