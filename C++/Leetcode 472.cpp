#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<string,int> umap;

    bool Helper(string A)
    {
        for (int i = 1; i < A.length(); i++)
        {
            string left = A.substr(0,i);
            string right = A.substr(i,A.length() - i);

            if (umap[left] && (umap[right] || Helper(right)))
            {
                return true;
            }
        }
        return false;
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for (int i = 0; i < words.size(); i++)
        {
            umap[words[i]]++;
        }

        vector<string> answer;
        for(int i = 0; i < words.size(); i++)
        {
            if (Helper(words[i]))
            {
                answer.push_back(words[i]);
            }
        }
        return answer;
    }
};