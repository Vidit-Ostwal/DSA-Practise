class Solution:
    def minPathSum(self, distance: List[List[int]]) -> int:
        rows = len(distance)
        columns = len(distance[0])

        # distance  = [[100000 for i in range(rows)] for j in range(columns)]
        print(distance)
       
        # Direct Memoization
        # distance[0][0] = grid[0][0]

        for i in range(rows):

            for j in range(columns):

                if (i == 0 and j == 0):
                    # First Cell
                    distance[0][0] = distance[0][0]

                elif (i == 0 and j != 0):
                    # First Row
                    print(i,j)
                    distance[i][j] = distance[i][j] + distance[i][j-1]

                elif (j == 0 and i != 0):
                    # First Column
                    distance[i][j] = distance[i][j] + distance[i-1][j]
                
                else:
                    distance[i][j] = distance[i][j] + min(distance[i-1][j],distance[i][j-1])
        
        print(distance)
        return distance[rows-1][columns-1]