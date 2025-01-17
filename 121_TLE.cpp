#include <bits/stdc++.h>
using namespace std;
// TLE kahy dp use hoyni . dp not possible constraints too high.


int go(int index, bool bought, int bPrice, vector<int> &prices)
{
    if (index == prices.size())
        return 0;

    int ans = 0;
    if (!bought)
    {
        ans = max(ans, go(index + 1, 0, 0, prices));             // Skip the day
        ans = max(ans, go(index + 1, 1, prices[index], prices)); // Buy stock
    }
    else
    {
        ans = max(ans, prices[index] - bPrice);           // Sell stock
        ans = max(ans, go(index + 1, 1, bPrice, prices)); // Skip the day
    }

    return ans;
}

int maxProfit(vector<int> &prices)
{
    return go(0, 0, 0, prices);
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices) << endl;

    return 0;
}
