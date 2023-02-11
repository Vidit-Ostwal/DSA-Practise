class Solution:
    Edges_Map = []
    DistanceR = []
    DistanceB = []

    def Helper(self, curr_node :  int, distance: int, type_edge :  int):
        
        if (type_edge == 1):
            # Red Edge
            if (self.DistanceR[curr_node] >  distance):
                self.DistanceR[curr_node] = distance
                for temp_list in self.Edges_Map[curr_node]:
                    next_node = temp_list[0]
                    type_edge = temp_list[1]
                    
                    if type_edge == -1:
                        self.Helper(next_node,distance+1,-1)
        
        elif (type_edge == -1):
            # Blue Edge
            if (self.DistanceB[curr_node] >  distance):
                self.DistanceB[curr_node] = distance

                for temp_list in self.Edges_Map[curr_node]:
                    next_node = temp_list[0]
                    type_edge = temp_list[1]
                    
                    if type_edge == 1:
                        self.Helper(next_node,distance+1,1)

                
    def shortestAlternatingPaths(self, n: int, redEdges: List[List[int]], blueEdges: List[List[int]]) -> List[int]:
        self.Edges_Map = [[] for i in range(n)]
        self.DistanceR = [1000000 for i in range(n)]
        self.DistanceB = [1000000 for i in range(n)]
        Distance = [1000000 for i in range(n)]
        
        for temp_list in redEdges:
            st_node = temp_list[0]
            des_node = temp_list[1]
            self.Edges_Map[st_node].append([des_node,1])
        
        for temp_list in blueEdges:
            st_node = temp_list[0]
            des_node = temp_list[1]
            self.Edges_Map[st_node].append([des_node,-1])

        self.DistanceR[0] = 0
        self.DistanceB[0] = 0

        # print(self.Edges_Map)

        for temp_list in self.Edges_Map[0]:
            next_node = temp_list[0]
            type_edge = temp_list[1]

            self.Helper(next_node,1,type_edge)
        

        for i in range(n):
            min_dis = min(self.DistanceR[i],self.DistanceB[i])

            if (min_dis == 1000000):
                Distance[i] = -1
            else:
                Distance[i] = min_dis

        return Distance
