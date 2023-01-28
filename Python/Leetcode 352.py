from ast import List


class SummaryRanges:
    # Dict = dict()

    def __init__(self):
        self.set = set()

    def addNum(self, value: int) -> None:
        self.set.add(value)


    def getIntervals(self) -> List[List[int]]:

        keys_list = sorted(list(self.set))
        answer_list = []
        index = 0
        while index < len(keys_list):

            start = keys_list[index]
            end = keys_list[index]

            while (index < len(keys_list) and (keys_list[index] - end <= 1)):
                end = keys_list[index]
                index = index + 1
            
            temp_list = [start,end]
            answer_list.append(temp_list)

        
        return answer_list


# Your SummaryRanges object will be instantiated and called as such:
# obj = SummaryRanges()
# obj.addNum(value)
# param_2 = obj.getIntervals()