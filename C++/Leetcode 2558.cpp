#include <cmath>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        
        for (int i = 0; i < gifts.size(); i++)
        {
            pq.push(gifts[i]);
        }
        
        while (k)
        {
            k--;
            
            int top = pq.top();
            
            pq.pop();
            
            long long sqrt = pow(top,0.5);
            
            pq.push(sqrt);
        }
        
        long long answer = 0;
        while (pq.size())
        {
            answer += pq.top();
            pq.pop();
        }
        
        return answer;
    }
};