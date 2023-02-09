#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        vector<unordered_set<string>> vect(26);

        for (int i = 0; i < ideas.size(); i++)
        {
            // All the word starting with the same letter are been compiled under the same letter
            vect[ideas[i][0] - 'a'].insert(ideas[i].substr(1));
        }

        long long answer = 0;
        for (int i = 0; i < 25; i++)
        {
            for (int j = i + 1; j <= 25; j++)
            {
                unordered_set<string> set1;

                set1.insert(vect[i].begin(),vect[i].end());
                set1.insert(vect[j].begin(),vect[j].end());

                answer += (set1.size() - vect[i].size())*(set1.size() - vect[j].size());
            }
        }
        return answer*2;

    }
};