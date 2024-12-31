#include <bits/stdc++.h>
using namespace std;

void dfs(int i, int j, int initialColor, int newColor, vector<vector<int>> &image)
{
  int n = image.size();
  int m = image[0].size();

  if (i < 0 || j < 0)
    return;
  if (i >= n || j >= m)
    return;
  if (image[i][j] != initialColor)
    return;

  image[i][j] = newColor;
  // 4 Sides:
  dfs(i - 1, j, initialColor, newColor, image);
  dfs(i + 1, j, initialColor, newColor, image);
  dfs(i, j - 1, initialColor, newColor, image);
  dfs(i, j + 1, initialColor, newColor, image);
  // 4 Corners
  dfs(i - 1, j - 1, initialColor, newColor, image);
  dfs(i - 1, j + 1, initialColor, newColor, image);
  dfs(i + 1, j - 1, initialColor, newColor, image);
  dfs(i + 1, j + 1, initialColor, newColor, image);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
  int initialColor = image[sr][sc];
  if (initialColor != newColor)
    dfs(sr, sc, initialColor, newColor, image);
  return image;
}

int main(int argc, char *argv[])
{
  cout << "ENTER N size of MAT:" << endl;
  int n;
  cin >> n;
  cout << "Enter elements: " << endl;

  vector<vector<int>> image;
  for (int i = 1; i <= n; i++)
  {
    vector<int> tmp;
    for (int j = 1; j <= n; j++)
    {
      int x;
      cin >> x;
      tmp.push_back(x);
    }
    image.push_back(tmp);
  }
  cout << "Enter rowNo colNo & newColor:" << endl;
  int sr, sc, newColor;
  cin >> sr >> sc;
  cin >> newColor;

  floodFill(image, sr, sc, newColor);

  cout << endl
       << endl;
  for (auto it : image)
  {
    for (auto elm : it)
    {
      cout << elm << " ";
    }
    cout << endl;
  }

  return 0;
}

/*
    3
    1 0 1
    0 1 0
    1 0 1

    1 1 5

*/