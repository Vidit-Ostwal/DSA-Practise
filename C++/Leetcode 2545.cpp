#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        vector<pair<int,int>> temp;
        vector<vector<int>> answer = vector<vector<int>>(score.begin(),score.end());
        
        for (int i = 0; i < score.size(); i++)
        {
            temp.push_back(make_pair(score[i][k],i));
        }
        
        sort(temp.begin(),temp.end());
        
        
        int n = temp.size();
        for (int i = 0; i < score.size(); i++)
        {
            int row = temp[n - i - 1].second;
            for (int j = 0; j < score[i].size(); j++)
            {
                answer[i][j] = score[row][j];
            }
            // score[i][k] = temp[i];
        }
        return answer;
             
    }
};