class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:

        if len(s1) > len(s2):
            return False
        
        Dict1 = dict()
        Dict2 = dict()

        for char in s1:
            Dict1[char] = Dict1.get(char,0) + 1

        end_index = 0

        while end_index < len(s1):
            Dict2[s2[end_index]] = Dict2.get(s2[end_index],0) + 1
            end_index = end_index + 1
        
        if Dict1 == Dict2:
            return True
        
        st_index = 0

        while end_index < len(s2):
            Dict2[s2[end_index]] = Dict2.get(s2[end_index],0) + 1
            Dict2[s2[st_index]] = Dict2.get(s2[st_index],0) - 1

            if Dict2[s2[st_index]] == 0:
                Dict2.pop(s2[st_index])

            if Dict2 == Dict1:
                return True
            
            end_index = end_index + 1
            st_index = st_index + 1
        
        return False