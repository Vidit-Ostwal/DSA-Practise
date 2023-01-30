class Solution:
    def isPalindromic(self,s: str) -> bool:
        temp = s[::-1]
        if (temp == s):
            return True
        return False

    def Helper(self, original_string: str, index : int,temp_list: List[str], level: int) -> List[List[str]]:
        
        if (index == len(original_string)):
            temp = []
            temp.append(temp_list)
            return temp

        global_string = ""
        parent_list = []

        while (index != len(original_string)):
            global_string += original_string[index]

            if (self.isPalindromic(global_string)):
                next_list = temp_list.copy()
                next_list.append(global_string)
                child_list = self.Helper(original_string,index+1,next_list,level+1)
                parent_list.extend(child_list)
            index = index + 1

        print(level, parent_list)
        return parent_list

    def partition(self, s: str) -> List[List[str]]:

        return self.Helper(s,0,[],1)