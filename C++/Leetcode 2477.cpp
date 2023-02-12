#include <cmath>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;


class Solution {
    vector<int> Parent;
    vector<int> Distance;
    vector<bool> Visited;
    vector<int> Person;
    unordered_map<int,vector<int>> umap;


public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;

        Parent = vector<int>(n,-1);
        Distance = vector<int>(n,INT_MAX);
        Person = vector<int>(n,1);

        int max_distance = -1;
        Person[0] = 0;

        for (int i = 0; i < roads.size(); i++)
        {
            umap[roads[i][0]].push_back(roads[i][1]);
            umap[roads[i][1]].push_back(roads[i][0]);
        }

        queue<int> Nodequeue;
        Nodequeue.push(0);

        Parent[0] = -1;
        Distance[0] = 0;

        while (Nodequeue.size())
        {
            int size = Nodequeue.size();

            while (size)
            {
                size--;
                int curr_node = Nodequeue.front();
                Nodequeue.pop();

                for (int i = 0; i < umap[curr_node].size(); i++)
                {
                    int next_node = umap[curr_node][i];

                    if (Distance[next_node] >  1 + Distance[curr_node])
                    {
                        Distance[next_node] = 1 + Distance[curr_node];
                        Parent[next_node] = curr_node;
                        Nodequeue.push(next_node);

                        max_distance = max(max_distance,Distance[next_node]);
                    }
                }
            }
        }

        queue<int> Nodes;
        unordered_map<int,vector<int>> umap1;

        for (int i = 0; i < Distance.size(); i++)
        {
            umap1[Distance[i]].push_back(i);
            
            if (max_distance == Distance[i])
            {
                Nodes.push(i);
            }
        }

        long long fuel_cost = 0;
        while (Nodes.size())
        {
            int size = Nodes.size();

            while (size)
            {
                size--;
                int curr_node = Nodes.front();

                Nodes.pop();
                int next_node = Parent[curr_node];
                int total_people = Person[curr_node];

                fuel_cost += (long long)(ceil(total_people / (double)seats));

                Person[next_node] += total_people;
                Person[curr_node] -= total_people;
            }
            max_distance--;

            for (int i = 0; i < umap1[max_distance].size() && max_distance; i++)
            {
                Nodes.push(umap1[max_distance][i]);
            }
        }
        return fuel_cost;
    }
};