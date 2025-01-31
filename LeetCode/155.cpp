#include <bits/stdc++.h>
using namespace std;

class MinStack
{

private:
    vector<int> v;
    vector<int> minVec;

public:
    MinStack() {}

    void push(int val)
    {
        if (minVec.empty() || val <= minVec.back())
        {
            minVec.push_back(val);
        }
        v.push_back(val);
    }

    void pop()
    {
        if (!v.empty())
        {
            if (minVec.back() == v.back())
            {
                minVec.pop_back();
            }
            v.pop_back();
        }
    }

    int top()
    {
        return v.empty() ? -1 : v.back();
    }

    int getMin()
    {
        return minVec.empty() ? -1 : minVec.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
