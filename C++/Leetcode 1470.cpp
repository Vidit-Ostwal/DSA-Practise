#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> vect;

        int j = n;
        for (int i = 0; i < n; i++)
        {
            vect.push_back(nums[i]);
            vect.push_back(nums[j]);
            j++;
        }
        return vect;
    }
};