#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
const int INF = INT_MAX;

vector<int> divisors[N];
int sum[N];

void sieve_divisors_and_sum_0f_divisors_Ofnumber()
{
    // O(n log n)

    divisors[1].push_back(1);
    sum[1] = 1;

    for (int i = 2; i <= N; i++)
    {
        for (int j = i; j <= N; j += i)
        {
            divisors[j].push_back(i);
            sum[j] += i;
        }
    }
}

int main(void)
{
    sieve_divisors_and_sum_0f_divisors_Ofnumber();

    for (int i = 1; i < 10; i++)
    {
        cout << i << " " << sum[i] << endl;
        for (auto val : divisors[i])
        {
            cout << val << " ";
        }
        cout << endl
             << endl;
    }

    return 0;
}