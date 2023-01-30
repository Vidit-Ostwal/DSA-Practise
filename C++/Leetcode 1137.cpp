#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        if (n <= 2)
        {
            return min(1,n);
        }

        int prev3 = 0;
        int prev2 = 1;
        int prev1 = 1;

        int answer = -1;
        for (int i = 3; i <= n; i++)
        {
            answer = prev3 + prev2 + prev1;
            prev3 = prev2;
            prev2 = prev1;
            prev1 = answer;
            // cout << i   << " " <<  answer << endl;
        }
        return answer;
    }
};