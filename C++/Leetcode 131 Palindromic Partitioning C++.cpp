#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool isPalindromic(string s)
    {
        string temp = s;
        reverse(temp.begin(),temp.end());

        if (!s.compare(temp))
        {
            return true;
        }
        return false;
    }

    vector<vector<string>> Helper(string original_string, int index, vector<string> temp_vect)
    {
        // No more elements to check
        if (index == original_string.length())
        {
            vector<vector<string>> temp;
            temp.push_back(temp_vect);
            return temp;
        }

        string global_string = "";
        vector<vector<string>> parent_vector;

        // Checking all the possibilities from this index 
        while (index != original_string.length())
        {
            global_string += original_string[index];

            if (isPalindromic(global_string))
            {
                temp_vect.push_back(global_string);
                vector<vector<string>> child_vector = Helper(original_string, index + 1, temp_vect);
                parent_vector.insert(parent_vector.end(),child_vector.begin(),child_vector.end());
                temp_vect.pop_back();
            }
            index++;
        }
        return parent_vector;
    }
public:
    vector<vector<string>> partition(string s) {
        return Helper(s,0,{});
    }
};