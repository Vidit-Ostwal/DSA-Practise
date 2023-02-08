#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> required_jumps(nums.size(),0);

        for (int i = nums.size() - 2; i >= 0; i--)
        {
            int total_jumps = nums[i];
            int temp_jumps_required = INT_MAX-1;

            for (int j = 1; j <= total_jumps && i + j < nums.size(); j++)
            {
                temp_jumps_required = min(temp_jumps_required, required_jumps[i+j]);
            }
            required_jumps[i] = temp_jumps_required + 1;
        }
        return required_jumps[0];
    }
};