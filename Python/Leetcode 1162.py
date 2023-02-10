from queue import Queue

class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        
        rows = len(grid)
        columns = len(grid[0])

        Distance = [[-1 for _ in range(0,rows)] for __ in range(0,columns)]

        queue = Queue()

        for row in range(rows):
            for col in range(columns):
                if grid[row][col] == 1:
                    Distance[row][col] = 0
                    queue.put([row,col])

        X = [-1,0,0,1]
        Y = [0,1,-1,0]

        answer = -1

        while queue.qsize():

            size = queue.qsize()
            while size:
                size = size - 1
                temp_list = queue.get()

                for i in range(4):
                    new_x = X[i] + temp_list[0]
                    new_y = Y[i] + temp_list[1]

                    if new_x >= 0 and new_y >= 0 and new_x < rows and new_y < columns and Distance[new_x][new_y] == -1:
                        Distance[new_x][new_y] = 1 + Distance[temp_list[0]][temp_list[1]]
                        queue.put([new_x,new_y])
                        answer = max(answer,Distance[new_x][new_y])

        return answer