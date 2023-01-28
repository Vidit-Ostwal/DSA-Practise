#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<int,vector<pair<int,int>>> umap;

    void mapping (vector<vector<int>> &flights)
    {
        for (int i = 0; i < flights.size(); i++)
        {
            umap[flights[i][0]].push_back(make_pair(flights[i][1],flights[i][2]));
        }
    }
     void show_vector(vector<int> vect)
 {
  for (auto &it: vect)
  {
   cout << it << " ";
  }
  cout << endl;
 }

public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        mapping (flights);

        vector<int> distance = vector<int>(n,INT_MAX);

        // Two very conflecting things are there first, you need to have a minimum prize and second stops now using dikstra's algo, pq might have an edge, but would restrict the number of stop condition, therefore use BFS, stops will automatically have a single condition


        // Node and the distance and the number of stops 
        queue<pair<int,int>> queue;
        queue.push(make_pair(src,0));
        distance[src] = 0;
        int stops = 0;
        while (queue.size() && stops <= k)
        {
            int size = queue.size();

            while (size)
            {
            int curr_node = queue.front().first;
            int cost = queue.front().second;
            queue.pop();
            
            for (int i = 0; i < umap[curr_node].size(); i++)
                {
                    int next_node = umap[curr_node][i].first;
                    int next_cost = umap[curr_node][i].second + cost;

                    if (distance[next_node] > next_cost)
                    {
                        distance[next_node] = next_cost;
                        queue.push(make_pair(next_node,next_cost));
                    }
                }
                size--;
            }
            // show_vector(distance);
            stops++;
        }
        if (distance[dst]  == INT_MAX)
        {
            return -1;
        }
        return distance[dst];
    }
};