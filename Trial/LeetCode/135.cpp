#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        vector<int> ans_arr(n, 1);

        // Left traversal:
        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
                ans_arr[i] = max(ans_arr[i], ans_arr[i - 1] + 1);
        }

        // Right traversal:

        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
                ans_arr[i] = max(ans_arr[i], ans_arr[i + 1] + 1);
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += ans_arr[i];
        }

        return ans;
    }
};

int main()
{
    vector<int> v = {7, 5, 3, 4, 4, 6};
    Solution s;
    cout << s.candy(v);
}