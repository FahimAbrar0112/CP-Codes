#include <bits/stdc++.h>
using namespace std;

// works fine if nums was not sorted
int removeDuplicates(vector<int> &nums)
{
    unordered_set<int> s;
    for (auto val : nums)
    {
        s.insert(val);
    }

    vector<int> tmp;

    for (int i = 0; i < nums.size(); i++)
    {
        auto it = s.find(nums[i]);
        if (it != s.end())
        {
            tmp.push_back(nums[i]);
            s.erase(it);
        }
    }

    int n = tmp.size();
    for (int i = 0; i < n; i++)
    {
        nums[i] = tmp[i];
    }
    return n;
}

int main(void)
{

    vector<int> v = {5, 4, 4, 4, 5, 1, 2, 4, 5, 3};
    // 5 4 1 2 3

    int n = removeDuplicates(v);
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl
         << n << endl;

    vector<int> v2 = {1, 2, 2, 3, 3, 4, 4, 5};
    ////////////
    n = removeDuplicates(v2);
    for (int i = 0; i < n; i++)
    {
        cout << v2[i] << " ";
    }
    cout << endl
         << n << endl;
}