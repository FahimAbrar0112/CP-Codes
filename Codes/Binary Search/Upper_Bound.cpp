#include <bits/stdc++.h>
using namespace std;

int Upper_Bound(vector<int> &v, int to_find)
{
  int lo = 0, hi = v.size() - 1;
  while (hi - lo > 1)
  {
    int mid = (hi + lo) / 2;
    //
    if (v[mid] <=to_find)
      lo = mid + 1;
    else
      hi = mid;
  }

  if (v[lo] > to_find)
    return lo;
  if (v[hi] > to_find)
    return hi;

  return -1;
}

int main(int argc, char *argv[])
{

  int n;
  cin >> n;

  vector<int> v;
  for (int i = 0; i < n; i++)
  {
    int tmp;
    cin >> tmp;
    v.push_back(tmp);
  }

  int target;
  cout << endl
       << "Target: ";
  cin >> target;

  int ind = Upper_Bound(v, target);
  cout << ind << " " << (ind != -1 ? v[ind] : -1) << endl;

  return 0;
}
/*

  4
  1 5 7 12
  5

  

  6
  2 3 4 6 7 8


8
1 5 12 13 14 20 25 40



*/