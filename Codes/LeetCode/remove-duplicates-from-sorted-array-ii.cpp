#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
const int INF = INT_MAX;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int count = 0;
        for (auto val : nums)
        {
            if (count < 2 || nums[count - 2] != val)
            {
                nums[count++] = val;
                // count++;
            }
        }
        return count;
    }
};

int main(void)
{

    return 0;
}