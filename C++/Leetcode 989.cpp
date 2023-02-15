#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> vect2(to_string(k).length(),0);

        string K = to_string(k);

        for (int i = 0; i < K.length(); i++)
        {
            vect2[i] = K[i] - '0';
        }

        int size = max(vect2.size(),num.size());

        while (num.size() < size)
        {
            num.insert(num.begin(),0);
        }

        while (vect2.size() < size)
        {
            vect2.insert(vect2.begin(),0);
        }

        int cary = 0;
        for (int i = vect2.size()-1; i >= 0; i--)
        {
            int total = vect2[i] + num[i] + cary;

            int last_digit = total % 10;
            cary = total / 10;

            num[i] = last_digit;
            // cout << cary << endl;
        }

        if (cary)
        {
            // cout << cary << endl;
            vector<int> temp;

            string cary_string = to_string(cary);
            // cout << cary_string << endl;
            for (int i = 0; i < cary_string.length(); i++)
            {
                temp.push_back(cary_string[i] - '0');
            }

            // for (int i =0; i < temp.size(); i++ )
            // {
            //     cout << temp[i] << endl;
            // }
            num.insert(num.begin(),temp.begin(),temp.end());
        }


        return num;
    }
};