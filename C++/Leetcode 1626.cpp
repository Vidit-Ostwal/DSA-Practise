#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> vect;

        for (int i = 0; i < scores.size(); i++)
        {
            vect.push_back(make_pair(ages[i],scores[i]));
        }

        sort(vect.begin(),vect.end());

        vector<int> DP(scores.size(),0);

        int size = scores.size();
        for (int i = 0; i < size; i++)
        {
            int answer = 0;
            int maxi = vect[i].second;
            for (int j = i - 1; j >= 0; j--)
            {
                if (vect[j].second <= maxi)
                {
                    answer = max(answer,DP[j]);
                }
            }
            DP[i] = maxi + answer;
        }
        int answer = -1;
        for (int i = 0; i < size; i++)
        {
            answer = max(answer, DP[i]);
        }
        return answer;
    }
};