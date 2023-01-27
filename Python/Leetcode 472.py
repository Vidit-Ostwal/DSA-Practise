class Solution:
    def Helper(self, word : string, temp_dict : dict) -> bool:
        for i in range(1,len(word)):
            left = word[:i]
            right = word[i:len(word)]

            if (left in temp_dict.keys()) and (right in temp_dict.keys() or self.Helper(right,temp_dict)):
                return True
        
        return False

    def findAllConcatenatedWordsInADict(self, words: List[str]) -> List[str]:
        concatenated_words = []
        temp_dict = dict() 

        for word in words:
            temp_dict[word] = 1

        for word in words:
            if self.Helper(word,temp_dict):
                concatenated_words.append(word)
        

        return concatenated_words