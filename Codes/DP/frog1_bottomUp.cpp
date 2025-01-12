#include <bits/stdc++.h>
using namespace std;
vector<int> heights;
vector<long long> dp;

int main(void)
{
    int n;
    cin >> n;

    dp.resize(n + 1, INT_MAX);
    heights.resize(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> heights[i];
    }

    dp[1] = 0;
    dp[2] = abs(heights[2] - heights[1]);

    for (int i = 3; i <= n; i++)
    {
        long long cost = INT_MAX;
        cost = min(cost, dp[i - 1] + abs(heights[i - 1] - heights[i]));
        cost = min(cost, dp[i - 2] + abs(heights[i - 2] - heights[i]));

        dp[i] = cost;
    }

    cout << dp[n] << endl;
}