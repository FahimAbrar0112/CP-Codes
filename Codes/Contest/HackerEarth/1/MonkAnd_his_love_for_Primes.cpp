#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
const int INF = INT_MAX;

bool isPrime[N];

void sieve(void)
{
    for (int i = 0; i < N; i++)
        isPrime[i] = true;

    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i < N; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j < N; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}

int main(void)
{
    sieve();

    string s;
    cin >> s;

    //  a- A =32
    int sum = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = (char)(s[i] + 32);
            sum += (int)s[i];
        }
        else
        {
            s[i] = (char)(s[i] - 32);
            sum -= (int)s[i];
        }
    }

    sum = abs(sum);
    if (isPrime[sum])
        cout << 1 << endl;
    else
        cout << 0 << endl;
    return 0;
}