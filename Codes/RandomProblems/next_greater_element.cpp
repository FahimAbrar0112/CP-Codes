#include<bits/stdc++.h>
using namespace std;

const int N=1e5+7;
const int INF = INT_MAX;

void NextGreaterElement(vector<int>&v,vector<int>&nge)
{
    stack<int>st; //index stack e diteso so nge teo index store hosse
    
    for(int i=0;i<v.size();i++)
    {
        while(!st.empty() && v[i]>v[st.top()])
        {
            nge[st.top()]=i;
            st.pop();
        }
        st.push(i);
        
    }
    while(!st.empty() )
    {
        nge[st.top()]=-1;
        st.pop();
    }
}

int main(void)
{
    
    int n;
    cin>>n;
    vector<int>v(n);
    vector<int>NGE(n,-1);

    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }

    NextGreaterElement(v,NGE); 

    for(int val:NGE)
    {
        cout<< ((val==-1)? -1:v[val] )<<" ";
    }
    cout<<endl;


    return 0;
}

/*
        6
        4 5 2 25 7 8

        5
        1 2 3 4 3
*/