#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s2, string s1) {
            // Reverse Analogy

        if (s1.length() > s2.length())
        {
            return {};
        }

        int length = s1.length();
        vector<int>answer;

        unordered_map<int,int> maps1;
        unordered_map<int,int> maps2;

        for (int i = 0; i < s1.length(); i++)
        {
            maps1[s1[i]]++;
        }

        int st_index = 0;

        for (st_index = 0; st_index < length; st_index++)
        {
            maps2[s2[st_index]]++;
        }

        if (maps1 == maps2)
        {
            // answer++;
            answer.push_back(0);
        }

        int last_index = 0;

        while (st_index < s2.length())
        {
            maps2[s2[st_index]]++;
            maps2[s2[last_index]]--;

            if (!maps2[s2[last_index]])
            {
                maps2.erase(s2[last_index]);
            }

            st_index++;
            last_index++;
            // cout << st_index  - last_index << endl;
            if (maps2 == maps1)
            {
                // cout << last_index << "   " << st_index << endl;
                answer.push_back(last_index);
                // return true;
            }
        }
        return answer;
    }
};