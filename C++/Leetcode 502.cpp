#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> vect;

        for (int i = 0; i < profits.size(); i++)
        {
            vect.push_back(make_pair(capital[i],profits[i]));
        }
        sort(vect.begin(),vect.end());


        int index = 0;
        priority_queue<int> pq;
        int profit = 0;
        while (k--)
        {
            while (index < vect.size() && vect[index].first <= w)
            {
                pq.push(vect[index].second);
                // w += vect[index].first;
                index++;
            }

            if (pq.size() == 0)
            {
                break;
            }
            // profit += pq.top();
            w += pq.top();
            pq.pop();
        }

        return w;
    }
};