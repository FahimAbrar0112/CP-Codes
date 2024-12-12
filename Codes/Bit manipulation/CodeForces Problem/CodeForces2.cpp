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

    akta company ase oikhane n ta worker job kore.
    ak ak jon particular kisu day te job kore let's say: person1 job kore 1,2,5,10,25,30 tarikhe masher.

    mashe 30 din .
    we want to assign an important task to 2 person.
 but they will be able to work on the project only when they are both available. Find two workers that are best for the job — maximize the number of days when both these workers are available.



        Let's say :
         person 0 ,1 and 2 =>
          these 3 people has common days 4.
          So we want all their names like whom can we select.




5
4
1 4 7 9
6
2 9 1 7 25 29
7
1 23 4 7 9 11 29
10
2 28 8 7 9 10 30 21 18 19
4
1 11 29 7


output:  0 2 => 4 days


 */

void printBinary(int n)
{
    for (int i = 31; i >= 0; i--)
    {
        cout << ((n >> i) & 1);
    }
    cout << endl;
}

int main(void)
{
    init_code();

    int n;
    cin >> n;

    vector<int> masks(n, 0);
    // masks[0] => mask of 1st person -> lokta kobe kobe kaj korte pare.

    int max_days = 0;
    unordered_set<int> persons;

    for (int i = 0; i < n; i++)
    {
        int noOF_days;
        cin >> noOF_days;
        for (int j = 0; j < noOF_days; j++)
        {
            int day;
            cin >> day;
            masks[i] = masks[i] | (1 << day);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int intersection = masks[i] & masks[j];
            int common_days_between_two = __builtin_popcount(intersection);

            if (common_days_between_two > max_days)
            {

                max_days = common_days_between_two;
                persons.clear();
                persons.insert(i);
                persons.insert(j);
            }
            else if (common_days_between_two == max_days)
            {
                persons.insert(i);
                persons.insert(j);
            }
        }
    }

    cout << "ANS: \n";
    for (auto it : persons)
    {
        cout << "Person-> " << it << endl;
    }
    cout << "#DYAS: " << max_days << endl;

    // cout << endl
    //      << endl;
    // cout << "Printing All: \n";
    // for (int i = 0; i < n; i++)
    // {
    //     cout << "Person: -> " << i << endl;
    //     cout << masks[i] << endl;
    //     printBinary(masks[i]);
    // }
}