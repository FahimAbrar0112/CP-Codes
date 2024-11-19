#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
const int INF = INT_MAX;

int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        char arr[n + 10][m + 10];

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> arr[i][j];
            }
        }

        // for(int i=1;i<=n;i++)
        // {
        //     for(int j=1;j<=m;j++)
        //     {
        //         cout<<arr[i][j];
        //     }
        // }

        int track1 = 0;
        string st = "vika";
        bool check = false;

        // cout<<endl;
        for (int j = 1; j <= m; j++)
        {
            bool flag = false;

            for (int i = 1; i <= n; i++)
            {
                // cout<<arr[i][j]<<" ##"<<track1<<endl;
                if (arr[i][j] == st[track1])
                {
                    // cout<<track1<<"> " << st[track1] <<endl;
                    track1++;
                    if (track1 == 4)
                    {
                        check = true;
                        break;
                    }
                    flag = true;
                    break;
                }
            }
            if (flag)
                continue;

            if (check)
                break;
        }

        if (check)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}

/*

1
4 4
vkak
iiai
avvk
viaa

*/