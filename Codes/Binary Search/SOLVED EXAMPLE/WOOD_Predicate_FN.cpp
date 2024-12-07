
// https://www.spoj.com/problems/EKO/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int n;  // # trees
long long m; // amount off weed required
vector<long long> trees;  // tree gular height

bool isWoodSufficient(int h)
{
  long long sum = 0;
  for (int i = 0; i < n; i++)
  {
    if (trees[i] >= h)
      sum += trees[i] - h;
  }

  return sum >= m;
}

int main(void)
{

  cin >> n >> m;

  for (int i = 0; i < n; i++)
  {
    int tmp;
    cin >> tmp;
    trees.push_back(tmp);
  }

  long long lo = 0, hi = 1e9, mid;  // tree height 0 to 1e9

  while (hi - lo > 1)
  {
    mid = (lo + hi) / 2;
    // T T T F F  F
    if (isWoodSufficient(mid))
    {
      lo = mid;
    }
    else
    {
      hi = mid - 1;
    }
  }

  if (isWoodSufficient(hi))
  {
    cout << hi << endl;
  }
  else
  {
    cout << lo << endl;
  }

  return 0;
}

/**

4 7
20 15 10 17

*/