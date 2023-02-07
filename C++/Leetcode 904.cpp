#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> map1;

        int st = 0;
        int ed = 0;
        int answer = 0;
        
        while (ed < fruits.size())
        {
            map1[fruits[ed]]++;

            if (map1.size() > 2)
            {
                map1[fruits[st]]--;

                if (map1[fruits[st]] == 0)
                {
                    map1.erase(fruits[st]);
                }
                st++;
            }

            answer = max(answer,(ed - st + 1));
            ed++;
        }
        return answer;
    }
};