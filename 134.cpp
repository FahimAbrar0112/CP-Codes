#include <bits/stdc++.h>
using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{

    if (accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0))
        return -1;

    int n = gas.size();

    int current_gas = 0;
    int startIndex = 0;

    for (int i = 0; i < n; i++)
    {
        current_gas += gas[i] - cost[i];
        if (current_gas < 0)
        {
            current_gas = 0;
            startIndex = i + 1;
        }
    }
    return startIndex;
}
