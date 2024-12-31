#include <bits/stdc++.h>
using namespace std;
#define ll Long Long
#define pb push_back
#define fr(a, b) for (int i = a; i < b; i++)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL << 60)
#define all(x) (x).begin(), (x).end()
#define prBouble(x) cout << fixed << setprecision(10) << x
#define triplet pair < ll, pair << ll, ll >>
#define goog(tno) cout << "Case #" << tno << ": "
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define read(x) \
    int x;      \
    cin >> x
void init_code()
{

    fast_io;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
// Code starts from here:

/*

 press :
          cntrl + alt + N

            cntrl + `    // press twice
*/

const int N = 1e5 + 10;
vector<int> g[N];
vector<bool> val(N, 0);
vector<int> primeCt(N, 0);

// Seive:
vector<bool> isPrime(N, 1);

void seive()
{
    for (int i = 2; i < N; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * 2; j < N; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}

//  DFS:
void dfs(int vertex, int par = 0)
{
    primeCt[vertex] += val[vertex];

    for (auto child : g[vertex])
    {
        if (child == par)
            continue;

        dfs(child, vertex);
        primeCt[vertex] += primeCt[child];
    }
}

int main(void)
{
    init_code();
    isPrime[0] = isPrime[1] = false;
    seive();

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;

        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        val[x] = isPrime[y];
    }

    dfs(1);

   

    long long ans = 0;

    for (int i = 2; i <= n; i++)
    {
        int part1 = primeCt[i];
        int part2 = primeCt[1] - part1;

        // if(ans< part1*1ll*part2)
        // {
        //     ans = max(ans, part1 * 1ll * part2);
        //     cout<<"ver: "<<i<<endl;
        // }

        ans = max(ans, part1 * 1ll * part2);
    }
    cout<<ans<<endl;
}
