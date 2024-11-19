#include<bits/stdc++.h>
using namespace std;



int main(int argc,char * argv[])
{   
      
    int t ;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        vector<vector<int> > v;
        for(int i=1;i<=n;i++)
        {   
           vector<int>tmp; 
            for(int j=1;j<n;j++)
            {   
                int x;
                cin >> x;
                tmp.push_back(x);
            }
            v.push_back(tmp);
        }

        map<int,int>mp;

        for(int i=0;i<n;i++)
        {
            mp[ v[i][0] ]++;
            //cout<<"y";
        }

        int ct=0,index=0;

        for(auto elm:mp)
        {
            int ind = elm.first;
            int count=elm.second;
            if(count>ct)
            {
                ct=count;
                index=ind;
            }
        }

        vector<vector<int>> final;

        for(auto elm:v)
        {
            if(elm[0]!=index)
            {
                final.push_back(elm);
                //cout<<"bal";
                break;
            }
        }
        cout<<index<<" ";
        for(auto elm:final[0])
        {
            cout<<elm<<" ";
        }
        cout<<endl;


    }

    



    return 0;
}