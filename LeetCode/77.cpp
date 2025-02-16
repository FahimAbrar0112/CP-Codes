#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> valied;

    vector<int> possibleValues;

    void generate(vector<int> &sub, int index, int &k)
    {

        if (sub.size() == k)
        {
            valied.push_back(sub);
            return;
        }
        
        if (index == possibleValues.size())
        {

            return;
        }

        sub.push_back(possibleValues[index]);
        generate(sub, index + 1, k);
        sub.pop_back();

        generate(sub, index + 1, k);
    }

    vector<vector<int>> combine(int n, int k)
    {
        for (int i = 1; i <= n; i++)
        {
            possibleValues.push_back(i);
        }

        vector<int> sub;

        generate(sub, 0, k);

        return valied;
    }
};
