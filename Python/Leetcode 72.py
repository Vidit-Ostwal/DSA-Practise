class Solution:
    DP = []
    def Helper(self,word1 : str, word2 : str, index1 : int, index2: int) -> int:
        len1 = len(word1)
        len2 = len(word2)

        if len1 == index1 or len2 == index2:
            return max(len2 - index2, len1 - index1)

        if self.DP[index1][index2] != -1:
            return self.DP[index1][index2]

        if word1[index1] == word2[index2]:
            temp_answer = self.Helper(word1,word2,index1+1,index2+1)
            self.DP[index1][index2] = temp_answer
            return temp_answer

        temp_answer = 1 + min(self.Helper(word1,word2,index1+1,index2+1),min(self.Helper(word1,word2,index1,index2+1),self.Helper(word1,word2,index1+1,index2)))
        self.DP[index1][index2] = temp_answer
        return temp_answer

    def minDistance(self, word1: str, word2: str) -> int:
        # temp_list = [-1 for _ in range(len(word1))]
        # print(temp_list)
        self.DP = [[-1 for i in range(len(word2))] for __ in range(len(word1))]
        return self.Helper(word1,word2,0,0)