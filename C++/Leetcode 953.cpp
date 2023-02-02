#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool Helper(string A, string B,vector<int> &temp)
    {
        int len = min(A.length(),B.length());

        for (int i = 0; i < len; i++)
        {
            if (temp[A[i] - 'a'] <  temp[B[i] - 'a'])
            {
                return true;
            }
            else if (temp[A[i] - 'a'] >  temp[B[i] - 'a'])
            {
                return false;
            }
        }

        if (A.length() > B.length())
        {
            return false;
        }
        return true;
    }
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> Dictionary(26,0);

        for (int i = 0; i < order.length(); i++)
        {
            Dictionary[order[i] - 'a'] = i;
        }

        for (int i = 0; i < words.size()-1; i++)
        {
            if (!Helper(words[i],words[i+1],Dictionary))
            {
                return false;
            }
        }
        return true;
    }
};