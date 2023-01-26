from queue import Queue

class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:

        ad_dict = {}
        cost_list = []

        for i in range(n):
            cost_list.append(1000000000)

        cost_list[src] = 0

        for temp_list in flights:
            temp_src = temp_list[0]
            temp_dst = temp_list[1]
            temp_cost = temp_list[2]

            # temp_list = ad_dict[temp_src]

            if temp_src in ad_dict:
                ad_dict[temp_src].append([temp_dst,temp_cost])
            else:
                ad_dict[temp_src] = []
                ad_dict[temp_src].append([temp_dst,temp_cost])

        # print(ad_dict)
        node_queue = Queue()
        node_queue.put([src,0])
        stops = 0

        while (node_queue.qsize() and stops <= k):

            size = node_queue.qsize()

            while size :
                # size = size - 1
                temp_list = node_queue.get()

                temp_src = temp_list[0]
                temp_cost = temp_list[1]

                # print(temp_src)
                # print(ad_dict[temp_src])

                if temp_src in ad_dict:
                    for next_list in ad_dict[temp_src]:
                        temp_next_dst = next_list[0]
                        temp_next_cst = next_list[1] + temp_cost

                        if (cost_list[temp_next_dst] >  temp_next_cst):
                            cost_list[temp_next_dst] = temp_next_cst
                            node_queue.put([temp_next_dst,temp_next_cst])

                size = size - 1
            stops = stops + 1

        if cost_list[dst] == 1000000000:
            return -1
        return cost_list[dst]        
