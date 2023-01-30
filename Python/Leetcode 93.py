class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        return self.Helper(s, 0, "", 4)

    
    def Helper(self, original_string: str, index : int, temp_string: str, part_left : int):
        
        if (index == len(original_string)):
            
            temp_list = []
            if (part_left == 0):
                temp_list.extend([temp_string])
            
            return temp_list

        if (part_left == 0):
           return []
        
        curr_number = 0
        final_list = []

        while (index < len(original_string)):
            curr_number = curr_number * 10 + int(original_string[index])

            if (curr_number >= 0 and curr_number <= 255):
                new_temp_string = ""
                if (part_left == 4):
                    new_temp_string = str(curr_number)
                else:
                    new_temp_string = temp_string + "." + str(curr_number)
                 
                final_list.extend(self.Helper(original_string,index+1,new_temp_string,part_left-1))
            else:
                break
            
            if (curr_number == 0):
                break

            index = index + 1

        return final_list