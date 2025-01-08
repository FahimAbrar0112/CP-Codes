// https : // codeforces.com/problemset/problem/295/B
#include <bits/stdc++.h>
using namespace std;

vector<vector<long long>> dist;
vector<int> deletion_order;

int main(void)
{
  int n;
  cin >> n;
  dist.resize(n + 5, vector<long long>(n + 5, 0));

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      cin >> dist[i][j];
    }
  }

  for (int i = 1; i <= n; i++)
  {
    int x;
    cin >> x;
    deletion_order.push_back(x);
  }

  reverse(deletion_order.begin(), deletion_order.end());
  vector<long long> ans;
  for (int k = 0; k < n; k++)
  {
    int k_node = deletion_order[k];
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {

        dist[i][j] = min(dist[i][j], dist[i][k_node] + dist[k_node][j]);
      }
    }
    long long sum = 0;

    for (int i = 0; i <= k; i++)
    {
      for (int j = 0; j <= k; j++)
      {
        int x = deletion_order[i];
        int y = deletion_order[j];
        sum += dist[x][y];
      }
    }

    ans.push_back(sum);
  }
  reverse(ans.begin(), ans.end());

  for (auto val : ans)
  {
    cout << val << "  ";
  }
}