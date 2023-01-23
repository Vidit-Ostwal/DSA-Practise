from ast import List


class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        if n == 1:
            return 1

        trusted_people = dict()
        trust_people = set()

        print(type(trusted_people))

        for x in trust:
            # print(x[1])
            # prev_value = trusted_people.get(x[1],0)
            trusted_people[x[1]] = trusted_people.get(x[1],0) + 1
            trust_people.add(x[0])
        
        for person,count in trusted_people.items():
            if count == n - 1:
                if not(person in trust_people):
                    return person
        
        return -1

