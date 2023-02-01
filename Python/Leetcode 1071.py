class Solution:
    def Helper(self, str1: str, str2: str) -> bool:
        temp = str2

        while (len(str2) != len(str1)):
            str2 = str2 + temp
        
        return str2 == str1


    def gcdOfStrings(self, str1: str, str2: str) -> str:
        length_str1 = len(str1)
        length_str2 = len(str2)

        if (length_str1 < length_str2):
            temp = str2
            str1 = str2
            str2 = temp

        for index in range(len(str2)-1,-1,-1):
            substring_length = index+1

            if length_str1 % substring_length == 0 and length_str2 % substring_length == 0:
                print(substring_length)
                sub = str2[0:substring_length]
        
                if (self.Helper(str1,sub) and self.Helper(str2,sub)):
                    return sub
        
        return ""
