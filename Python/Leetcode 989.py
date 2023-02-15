class Solution:
    def addToArrayForm(self, num: List[int], k: int) -> List[int]:
        
        # print()
        carry_backward = 0
        temp_string = str(k)
        size = max(len(temp_string),len(num))

        num_string = []

        for char in temp_string:
            num_string.append(int(char) - int('0'))
        
        while (len(num_string) < size):
            num_string.insert(0,0)

        while (len(num) < size):
            num.insert(0,0)

        # print(num_string,num)
        index = len(num) - 1
        while index >= 0:
            # print(index)
            new_number  = num_string[index] + carry_backward + num[index]
            new_digit = new_number % 10
            carry_backward = int(new_number / 10)
            num[index] = new_digit
            index = index - 1
            # print(num)

        if carry_backward:
            temp = str(carry_backward)

            for char in temp:
                # print(char)
                num.insert(0,int(char) - int('0'))
        
        return num
