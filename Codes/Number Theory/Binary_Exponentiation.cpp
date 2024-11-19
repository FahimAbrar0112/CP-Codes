#include <bits/stdc++.h>
using namespace std;
 long long binMultiply(long long a, long long b);
const int M = 1e9 + 10;

//This code will work for b<=18


// Binary exponentiation using recursion :
int binExpRec(int a, int b)
{
    if (b == 0)
        return 1;
    long long res = binExpRec(a, b / 2);
    if (b & 1)
        return (a * (res * res) % M) % M;
    else
        return (res * res) % M;
}

//binary expo using iterative method:

long binExpItr(long  a, long b)
{
    long ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = binMultiply(ans, a); 
        }
        b >>= 1;
        a  = binMultiply(a, a);
    }
    return ans;
}

// use binMultiply when 2 numbers are very big and calculations 
// will be done in log(b) complexity.

long long binMultiply(long long a, long long b)
{  
    // b can't be zero
    // if b is 0 then while loop doesnt work and it returns  o 
    
    long long ans = 0;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans + a) % M;
        }
        b >>= 1;
        a  =( a + a)%M;
    }
    return ans;
}

int main(void)
{

    // cout << binExpRec(5, 13) << endl;
    // int val = pow(5, 13);

    // val %= M;
    // cout << val << endl;

    // cout << binExpItr(5, 13) << endl;
    // cout << binMultiply(5, 13) << endl;


    /*
        calculate:
        ( (7^100) ^ (12345678) ) %  (1e9+10) 
    
    */

    long long a=7,b=100;
    long long ans1 = binExpItr(a,b);
    long long ans2 = 12345678;
    long long ans  = binExpItr(ans1,ans2) %M ;
    cout<<ans1<<" "<<ans2<<" "<<ans<<endl;

    //cout<< binExpItr(7,13) % M << endl;


    return 0;
}