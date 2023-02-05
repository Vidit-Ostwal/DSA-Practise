
class Solution:
    def Helper(self, s1 : str) -> int:
        Vowel_list = ['a','e','o','i','u']
        
        start_index = 0
        end_index = len(s1) - 1
        
        if (s1[start_index] in Vowel_list and s1[end_index] in Vowel_list):
            return 1
        
        return 0
    
        
    def vowelStrings(self, words: List[str], queries: List[List[int]]) -> List[int]:
        Temp_List = []
        
        for temp_string in words:
            Temp_List.append(self.Helper(temp_string))
        
        PrefixList = []
        PrefixList.append(0)
        
        temp_sum = 0
        
        for integer in Temp_List:
            
            temp_sum = temp_sum + integer
            PrefixList.append(temp_sum)
        
        QueryList = []
        
        for temp_list in queries:
            st_index = temp_list[0]
            end_index = temp_list[1]
            
            QueryList.append(PrefixList[end_index+1] - PrefixList[st_index])
        
        return QueryList
            
            
        