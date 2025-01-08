// https : // www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-campers/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

vector<int> parents(N, 0);
vector<int> Size(N, 0);
multiset<int> sizes;

void make(int v)
{
    parents[v] = v;
    Size[v] = 1;
    sizes.insert(1);
}

int find(int v)
{
    if (v == parents[v])
        return v;

    return parents[v] = find(parents[v]);
}

void merge(int a, int b)
{
    auto it_a = sizes.find(Size[a]);
    sizes.erase(it_a);
    auto it_b = sizes.find(Size[b]);
    sizes.erase(it_b);

    sizes.insert(Size[a] + Size[b]);
}
void Union(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a != b)
    {
        if (Size[a] < Size[b])
            swap(a, b);
        parents[b] = a;
        merge(a, b);
        Size[a] += Size[b];
    }
}

int main(void)
{
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
    {
        make(i);
    }
    while (q--)
    {
        int x, y;
        cin >> x >> y;

        Union(x, y);

        int minimum = *sizes.begin();
        int maximum = *(--sizes.end());
        cout << maximum - minimum << endl;
    }
}

/*

2 1
1 2


*/