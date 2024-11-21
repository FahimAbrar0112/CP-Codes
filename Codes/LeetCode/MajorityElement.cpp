#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
const int INF = INT_MAX;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int index = 0;
        int candidate = 0;

        for (auto val : nums)
        {
            if (index == 0)
            {
                candidate=val;
                // index++;
            }

            if (candidate==val)
             index++;
            else
             index--; 
        }

        return candidate;
    }
};

int main(void)
{
    vector<int> v = {1, 3, 6, 5, 5, 2, 5, 4, 5, 5};

    Solution s;

    cout << s.majorityElement(v) << endl;

    return 0;
}