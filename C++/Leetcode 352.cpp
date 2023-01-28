#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

class SummaryRanges {
    map<int,int> umap;
    // priority_queue<int,vector<int>,greater<int>> pq;
public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        umap[value]++;
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> answer;

        auto it = umap.begin();

        while (it != umap.end())
        {
            int start = it -> first;
            int last = it -> first;

            while (it != umap.end() && it -> first - last <= 1)
            {
                last = it -> first;
                it++;
            }
            answer.push_back({start,last});
        }

        return answer;

    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */