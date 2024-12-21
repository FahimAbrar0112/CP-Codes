#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{

    if (n == 1)
        return 0;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

int main(void)
{   
    
    for(int i=1;i<=100;i++)
    {
        cout<<i<<"  "<<isPrime(i)<<endl;
    }



}