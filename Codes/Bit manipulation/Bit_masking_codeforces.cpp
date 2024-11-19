#include<bits/stdc++.h>
using namespace std;

const int N=1e5+7;
const int INF = INT_MAX;



int main(void)
{
    int n;
    cin>>n;
    vector<int> masks(n,0) ;
    for(int i=0;i<n;i++)
    {
        int m;
        cin>>m;
        for(int j=0;j<m;j++)
        {
            int mask;
            cin>>mask;
            masks[i] |= (1<<mask) ;
        }
    }

    int person1=-1,person2=-1;
    int max=-1;
    

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int intersection = (masks[i] & masks[j]);
            int commonDays = __builtin_popcount(intersection);
            if(commonDays > max)
            {
                max = commonDays;
                person1=i;
                person2=j;
            }
        }
    }

    cout<<person1<<" "<<person2<<" "<<max<<endl;




    return 0;
}


/*

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



op: 0 2 4 

*/