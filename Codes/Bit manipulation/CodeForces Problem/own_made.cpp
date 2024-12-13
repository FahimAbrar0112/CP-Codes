#include <bits/stdc++.h>
using namespace std;
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

void init_code()
{

    fast_io;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

/*

https://codeforces.com/blog/entry/73558

 */

/*

    akta market e 100 typer fol ase.
    n ta lok market e gelo .
    protteke kisu fol nise.

    print the common fruits.



    5

    4
    1 10 50 100
    5
    1 7 12 20 100
    3
    1 5 100
    4
    100 5 10 1
    2
    1 100





    Output:
     1 100


 */

void printBinary(string n)
{
    for (int i = 0; i < n.size(); i++)
    {
        cout << n[i];
    }
    cout << endl
         << endl;
}

string AND_Operation(string s1, string s2)
{
    string tmp;
    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] == 'T' && s2[i] == 'T')
            tmp.push_back('T');
        else
            tmp.push_back('F');
    }
    return tmp;
}

int main()
{
    init_code();
    // 0 Based array:
    //  0 1 ..... 99

    int n;
    cin >> n;

    vector<string> s;
    for (int i = 0; i < n; i++)
    {
        string tmp;

        for (int j = 0; j < 100; j++)
        {
            tmp.push_back('F');
        }
        s.push_back(tmp);
    }

    for (int i = 0; i < n; i++)
    {
        int fruit_ct;
        cin >> fruit_ct;

        for (int j = 0; j < fruit_ct; j++)
        {
            int selected_fruit;
            cin >> selected_fruit;
            s[i][selected_fruit - 1] = 'T';
        }
    }

    // string temp = s[0];

    // for (auto val : s)
    // {
    //     printBinary(temp);
    // }

    string intersection;
    for (int i = 0; i < 100; i++)
    {
        intersection.push_back('T');
    }

    for (int i = 0; i < n; i++)
    {
        intersection = AND_Operation(intersection, s[i]);
    }

    // printBinary(intersection);

    for (int i = 0; i < intersection.size(); i++)
    {
        if (intersection[i] == 'T')
            cout << i + 1 << " ";
    }
    cout << endl;
}