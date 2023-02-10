#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        // Reverse BFS

        int rows = grid.size();
        int columns = grid[0].size();

        vector<vector<int>> Distance = vector<vector<int>>(rows, vector<int>(columns,-1));

        queue<pair<int,int>> pq;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                if (grid[i][j])
                {
                    Distance[i][j] = 0;
                    pq.push(make_pair(i,j));
                }
            }
        }

        int X[] = {-1,0,0,1};
        int Y[] = {0,1,-1,0};

        // int dis = 1
        int answer = -1;

        while (pq.size())
        {
            int size = pq.size();

            while (size)
            {
                size--;

                auto it = pq.front();
                int x = it.first;
                int y = it.second;
                pq.pop();

                for (int i = 0; i < 4; i++)
                {
                    int new_x = x + X[i];
                    int new_y = y + Y[i];

                    if (new_x >= 0 && new_y >= 0 && new_x < rows && new_y < columns && Distance[new_x][new_y] == -1)
                    {
                        Distance[new_x][new_y] = 1 + Distance[x][y];
                        pq.push(make_pair(new_x,new_y));
                        answer = max(answer,Distance[new_x][new_y]);
                    }
                }
            }
        }
        return answer;
    }
};
