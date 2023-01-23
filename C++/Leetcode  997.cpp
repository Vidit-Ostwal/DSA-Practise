#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        if (n == 1)
        {
            return 1;
        }
        unordered_map<int,int> trust_map;
        unordered_map<int,int> ptrust_map;
        for (int i = 0; i < trust.size(); i++)
        {
            trust_map[trust[i][1]]++;
            ptrust_map[trust[i][0]]++;
        }

        auto it = trust_map.begin();

        while (it != trust_map.end())
        {
            if (it -> second == n-1 && !ptrust_map[it->first])
            {
                return it -> first;
            }
            it++;
        }
        return -1;
    }
};