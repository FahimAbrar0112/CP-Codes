
#include<bits/stdc++.h>
using namespace std;

const int N=1e5+7;
const int INF = INT_MAX;


// utility function to calculate a%m
unsigned int aModM(string s, unsigned int mod)
{
    unsigned int number = 0;
    for (unsigned int i = 0; i < s.length(); i++)
    {
        // (s[i]-'0') gives the digit value and form
        // the number
        number = (number*10 + (s[i] - '0'));
        number %= mod;
    }
    return number;
}


int main(void)
{   

    string a = "1234567";
    int M=1e9+7;

    cout<<aModM(a, M)<<endl;
    


    return 0;
}