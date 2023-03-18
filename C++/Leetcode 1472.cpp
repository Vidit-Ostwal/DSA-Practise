#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

class BrowserHistory {
    stack<string> Backward;
    stack<string> Forward;
public:
    BrowserHistory(string homepage) {
        Backward.push(homepage);
    }
    
    void visit(string url) {
        Backward.push(url);
        while (Forward.size())
        {
            Forward.pop();
        }
    }
    
    string back(int steps) {
        while (steps && Backward.size())
        {
            Forward.push(Backward.top());
            steps--;
            Backward.pop();
        }

        if (!Backward.size())
        {
            Backward.push(Forward.top());
            Forward.pop();
        }
        return Backward.top();
    }
    
    string forward(int steps) {
        while (steps && Forward.size())
        {
            steps--;
            Backward.push(Forward.top());
            Forward.pop();
        }

        return Backward.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */