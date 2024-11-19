#include<bits/stdc++.h>
using namespace std;
const int N=10;
int profit[N];
int deadline[N];
int slot;
int job;

void jobScheduling(vector<vector<int>> &jobs)
{
    vector<pair<int,int>>p(job);
    for(int i=0; i<job; i++)
    {
        p[i].first=jobs[i][1];
        p[i].second=jobs[i][0];
        //cout<<p[i].first<<" "<<p[i].second<<endl;
    }
    bool check[job+1];
    int money=0;
    sort(p.rbegin(),p.rend());
    for(int i=1; i<=slot; i++)
    {
        check[i]=true;
    }
    for(int i=0; i<job; i++)
    {
        int pro=p[i].first;
        int dline=p[i].second;
        //cout<<pro<<" "<<dline<<endl;
        for(int j=dline; j>0; j--)
        {
            if(check[j]==true)
            {
                check[j]=false;
                money+=pro;
                break;
            }
        }
        //cout<<money<<" aa "<<endl;
    }
    cout<<money<<endl;

}
int main()
{
    int n;
    cin>>n;
    slot=0;
    job=n;
    vector<vector<int>>jobs;
    for(int i=0; i<n; i++)
    {
        vector<int>v;
        for(int j=0; j<1; j++)
        {
            int n1,n2;
            cin>>n1>>n2;
            v.push_back(n1);
            v.push_back(n2);
            if(n1>slot)
            {
                slot=n1;
            }
        }
        jobs.push_back(v);
    }
    jobScheduling(jobs);

}
