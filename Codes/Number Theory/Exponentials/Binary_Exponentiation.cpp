#include <bits/stdc++.h>
using namespace std;
long long binMultiply(long long a, long long b);
const int M = 1e9 + 10;
/*
    inbuilt pow funct ,  pow(a,b) => it returns double data type.
    double can store big data but trade off of precision.
    SO we need to avoid pow func.

*/

//   a and b and M <= 10^9 range

// Binary exponentiation using recursion :
int binExpRec(int a, int b)
{
    // O(log b)
    if (b == 0)
        return 1;
    long long res = binExpRec(a, b / 2);
    if (b & 1)
        return (a * (res * res) % M) % M;
    else
        return (res * res) % M;
}

// binary expo using iterative method:

int binExpItr(int a, int b)
{
    long long ans = 1;
    while (b)
    {
        if (b & 1)
        {
            // ans = ans * a;

            ans = (ans * a) % M;
        }
        b >>= 1;
        // a = a * a;
        a = (a * a) % M;
    }
    return ans;
}

int main(void)
{
    long long x = (long long)pow(5, 13);
    cout << "X: " << x << "  " << x % M << endl;
    cout << "binExpRec: " << binExpRec(5, 13) << endl;
    // int val = pow(5, 13);

    // val %= M;
    // cout << val << endl;

    cout << "binExpItr: " << binExpItr(5, 13) << endl;
   
     

    return 0;
}

