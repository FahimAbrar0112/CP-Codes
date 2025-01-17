#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{

    int ans = 0;
    int n = prices.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            ans = max(ans, prices[j] - prices[i]);
        }
    }

    return ans;
}
int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices) << endl;

    return 0;
}