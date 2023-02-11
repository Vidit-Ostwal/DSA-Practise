#include <cmath>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<int,vector<pair<int,int>>> edges;

    vector<int> DistanceR;
    vector<int> DistanceB;

    void Helper(int curr_node, int distance, bool edge)
    {
        if (edge)
        {
            // Red Edge are considered True
            if (DistanceR[curr_node] >  distance)
            {
                DistanceR[curr_node] = distance;

                for (int i = 0; i < edges[curr_node].size(); i++)
                {
                    int next_node = edges[curr_node][i].first; 
                    int type_edge = edges[curr_node][i].second;

                    if (type_edge == -1)
                    {
                        Helper(next_node,distance+1,false);
                    }
                }
            }
        }
        else
        {
            // Blue Edge are considered False
             if (DistanceB[curr_node] >  distance)
            {
                DistanceB[curr_node] = distance;

                for (int i = 0; i < edges[curr_node].size(); i++)
                {
                    int next_node = edges[curr_node][i].first; 
                    int type_edge = edges[curr_node][i].second;

                    if (type_edge == 1)
                    {
                        Helper(next_node,distance+1,true);
                    }
                }
            }
        }
        return ;
    }
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        DistanceR = vector<int>(n,INT_MAX-1);
        DistanceB = vector<int>(n,INT_MAX-1);
        
        for (int i = 0; i < redEdges.size(); i++)
        {
            edges[redEdges[i][0]].push_back(make_pair(redEdges[i][1],1));
        }

        for (int i = 0; i < blueEdges.size(); i++)
        {
            edges[blueEdges[i][0]].push_back(make_pair(blueEdges[i][1],-1));
        }

        DistanceR[0] = 0;
        DistanceB[0] = 0;

        for (int i = 0; i < edges[0].size(); i++)
        {
            int next_node = edges[0][i].first;
            int type_edge = edges[0][i].second;

            Helper(next_node,1,(type_edge == 1) ? true : false);
        }
        vector<int> Distance = vector<int>(n,INT_MAX-1);

        for (int i = 0; i < n; i++)
        {
            int mini = min(DistanceR[i],DistanceB[i]);
            Distance[i] = (mini == INT_MAX-1) ? -1 : mini;
        }
        return Distance;
    }
};