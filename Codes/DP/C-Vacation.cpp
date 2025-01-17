// https : // atcoder.jp/contests/dp/tasks/dp_c

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v[4]; // a b c => array
                  // 1 2 3
vector<vector<int>> dp;

int func(int day, int prevActivities)
{
    if (day > n)
        return 0;

    if (dp[day][prevActivities] != -1)
        return dp[day][prevActivities];
    int ans = 0;

    for (int i = 1; i <= 3; i++)
    {
        if (prevActivities != i)
            ans = max(ans, func(day + 1, i) + v[i][day]);
    }

    return dp[day][prevActivities] = ans;
}

int main(void)
{

    cin >> n;
    dp.resize(n + 1, vector<int>(4, -1));

    for (int i = 0; i <= 3; i++)
    {
        v[i].resize(n + 1);
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> v[1][i] >> v[2][i] >> v[3][i];
    }

    cout << func(1, 0) << endl;
}