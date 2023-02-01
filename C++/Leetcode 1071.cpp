#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool Helper(string Parent, string Child)
    {
        string temp_child = Child;
        while (Child.length() != Parent.length())
        {
            Child += temp_child;
        }
        if (Child.compare(Parent) == 0)
        {
            return true;
        }
        return false;
    }
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1.length() < str2.length())
        {
            string temp = str1;
            str1 = str2;
            str2 = temp;
        }

        //  Str1 is longer string now

        for (int i = str2.length()-1; i >= 0; i--)
        {
            int substring_length = i+1;

            if (str2.length() % substring_length == 0 && str1.length() % substring_length == 0)
            {
                string sub = str2.substr(0,substring_length);

                if (Helper(str2,sub) && Helper(str1,sub))
                {
                    return sub;
                }
            }
        }
        return "";
    }
};