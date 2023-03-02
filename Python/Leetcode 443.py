class Solution:
    def compress(self, chars: List[str]) -> int:
        temp_list = []

        st = 0
        length = 0

        while st < len(chars):
            curr_st = st
            count = 0

            while st < len(chars) and chars[st] == chars[curr_st]:
                count = count + 1
                st = st + 1
            
            temp_list.append(chars[curr_st])
            length = length + 1

            if count > 1:
                temp_count = str(count)

                for ch in temp_count:
                    temp_list.append(ch)
                
                length = length + len(temp_count)
        
        for index in range(min(len(chars),len(temp_list))):
            chars[index] = temp_list[index]
        
        for index in range(len(chars),len(temp_list)):
            chars.append(temp[index])
        
        return length