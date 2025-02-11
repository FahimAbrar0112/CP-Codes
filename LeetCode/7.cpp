#include <bits/stdc++.h>
using namespace std;
 
class Solution
{
public:
    int reverse(int x)
    {
        long long ans = 0;  

        while (x)
        {
            ans = ans * 10 + x % 10;
            cout << ans << endl;
            x /= 10;
        }

        return (ans > INT_MAX || ans < INT_MIN) ? 0 : ans;
    }
};

int main()
{

    Solution s;

    cout << s.reverse(-15) << endl;
}