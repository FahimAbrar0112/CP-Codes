// https : // atcoder.jp/contests/dp/tasks/dp_d
#include <bits/stdc++.h>
using namespace std;

vector<vector<long long>> dp;
// O( N * wt) => dp table dekhe =>  int ind, int wt_left=> 2 var changing
long long knapsack(int ind, int wt_left, vector<int> &weights, vector<int> &prices)
{
  // Func(ind,0) bag e jayga nai
  if (wt_left == 0)
    return 0;
  // func(-1,amount) bag e jayga ase but element r nai
  if (ind < 0)
    return 0;

  if (dp[ind][wt_left] != -1)
    return dp[ind][wt_left];

  // Dont choose item at ind
  long long ans = knapsack(ind - 1, wt_left, weights, prices);

  // Choose item at ind
  if (wt_left - weights[ind] >= 0)
    ans = max(ans + 0ll, knapsack(ind - 1, wt_left - weights[ind], weights, prices) + prices[ind]);

  return dp[ind][wt_left] = ans;
}

int main()
{

  vector<int> weights;
  vector<int> prices;
  int n, wt_left;
  cin >> n >> wt_left;

  for (int i = 0; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    weights.push_back(x);
    prices.push_back(y);
  }
  dp.resize(n + 1, vector<long long>(wt_left + 5, -1));

  cout << knapsack(n - 1, wt_left, weights, prices)
       << endl;

  return 0;
}
