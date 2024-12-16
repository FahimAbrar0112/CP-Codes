#include <bits/stdc++.h>
using namespace std;

long long binExp(long long a, long long b, long long M)
{
    long long ans = 1;

    while (b)
    {
        if (b & 1)
            ans = (ans * a) % M;
        b >>= 1;
        a = (a * a) % M;
    }

    return ans;
}

int superPow(int a, vector<int> &b)
{

    long long B = 0;

    

    reverse(b.begin(), b.end());
    for (int i = 0; i < b.size(); i++)
    {
        long long p = binExp(10, i, 1140);
        B += ((b[i] % 1140) * p) % 1140;
    }

    return binExp(a, B, 1337);
}

int main(void)
{
    int a = 2147483647;
    vector<int> b = {2, 0, 0};

    cout << superPow(a, b) << endl;

    // cout<<binMultiply(10,2,1140)<<endl;

    return 0;
}