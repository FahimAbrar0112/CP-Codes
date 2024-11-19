#include <bits/stdc++.h>
using namespace std;


// log(n)
int digitSum(int n)
{
    if (n == 0)
        return 0;

    return digitSum(n / 10) + (n % 10);
}

int main(void)
{
    int n = 10345;
    cout << digitSum(n) << endl;
}