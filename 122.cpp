#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{

    int profit = 0;
    int buy = INT_MAX;
    int prev = prices[0];

    for (int i = 0; i < prices.size(); i++)
    {
        if (prices[i] < buy)
            buy = prices[i];

        if (prices[i] - buy > 0)
        {
            profit += prices[i] - buy;
            buy = prices[i];
        }
    }

    return profit;
}

int main(void)
{
}