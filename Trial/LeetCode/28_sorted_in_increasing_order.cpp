#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    set<int> s;
    for (int i = 0; i < nums.size(); i++)
    {
        s.insert(nums[i]);
    }
    int i = 0;
    for (auto it : s)
    {
        nums[i] = it;
        i++;
    }
    return s.size();
}

int main(void)
{

    vector<int> v = {1,2,2,3,3,4,4,5};
    // 5 4 1 2 3

    int n = removeDuplicates(v);
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl
         << n << endl;
}