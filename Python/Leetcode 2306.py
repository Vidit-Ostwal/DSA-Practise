class Solution:
    def distinctNames(self, ideas: List[str]) -> int:
        Vect = [set() for _ in range(26)]
        # print(Vect)

        for string in ideas:
            Vect[ord(string[0]) - ord('a')].add(string[1:])

        # print(Vect)
        answer = 0
        for i in range(0,25):
            

            j = i + 1
            while j < 26:
                set1 = set()
                set1.update(Vect[i])
                set1.update(Vect[j])
                print(set1)
                answer = answer + (len(set1) - len(Vect[i]))*(len(set1) - len(Vect[j]))
                j = j + 1
            # print(answer)
        return answer*2

