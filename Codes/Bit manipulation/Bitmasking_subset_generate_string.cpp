#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
const int INF = INT_MAX;

vector<string> generate(string &nums)
{
    int n = nums.size();
    int subset_size = (1 << n);
    vector<string> subsets;
    for (int mask = 0; mask < subset_size; mask++)
    {
        string subset;
        for (int bit = 0; bit < n; bit++) 
        // for (int bit = n-1; bit>=0; bit--)
        {
            if (mask & (1 << bit))
            {
                subset.push_back(nums[bit]);
            }
        }
        subsets.push_back(subset);
    }

    return subsets;
}

int main(void)
{ 
    string s="abc";
    // cin >> s;


    auto subsets = generate(s);

    cout << subsets.size() << endl;
    for (auto subset : subsets)
    {
        for (auto val : subset)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}