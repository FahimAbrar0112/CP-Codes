#include <bits/stdc++.h>
using namespace std;

/*



    [capture](parameters) -> return_type {
    // Function body
    };

    OR,

    [capture](parameters)  {
    // Function body
    };


*/

auto foo = [](int a)
{
    return a + 10;
};

int func(int a)
{
    return a + 10;
}

int main(void)
{
    cout << [](int a)
    { return a + 10; }(5) << endl;
    cout << func(5) << endl; // Same

    cout << foo(5) << endl;

    cout <<  [](int a,int b){return a+b;}(5,6) << endl;
}