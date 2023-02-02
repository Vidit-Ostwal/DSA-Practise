class Solution:
    def Helper(self, str1: str, str2: str, Dict : List) -> bool:
        min_length = min(len(str1),len(str2))

        for index in range(0,min_length):
            if Dict[ord(str1[index]) - ord('a')] < Dict[ord(str2[index]) - ord('a')]:
                return True
            
            elif Dict[ord(str1[index]) - ord('a')] > Dict[ord(str2[index]) - ord('a')]:
                return False
        
        if (len(str1) > len(str2)):
            return False
        
        return True

    def isAlienSorted(self, words: List[str], order: str) -> bool:
        Dict = []

        for i in range(0,26):
            Dict.append(0)

        for i in range(0,len(order)):
            # print(i)
            Dict[ord(order[i]) - ord('a')] = i
        
        for i in range(0,len(words)-1):

            print(i)
            if not self.Helper(words[i],words[i+1],Dict):
                return False
            
        return True
