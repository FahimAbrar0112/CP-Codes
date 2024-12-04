#include <bits/stdc++.h>
using namespace std;

vector<int> NGE(vector<int> &v)
{
    vector<int> nge(v.size());
    stack<int> st;

    for (int i = 0; i < v.size(); i++)
    {
        if (st.empty())
        {
            st.push(i);
        }
        else
        {
            while (v[i] > v[st.top()])
            {
                nge[st.top()] = v[i];
                st.pop();
                if (st.empty())
                    break;
            }
            st.push(i);
        }
    }

    while (!st.empty())
    {
        nge[st.top()] = -1;
        st.pop();
    }
    return nge;
}

void show(vector<int> &v, vector<int> &nge)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " " << nge[i] << endl;
    }
}

int main(void)
{
    int n;
    cin >> n;
    vector<int> v(n);

    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }

    auto nge = NGE(v);
    show(v, nge);
}