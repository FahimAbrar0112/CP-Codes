#include<bits/stdc++.h>
using namespace std;
#define ll Long Long
#define pb push_back
#define fr(a,b) for(int i=a; i < b; i++)
#define rep(i,a,b) for(int i=a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(),(x).end()
#define prBouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<<ll,ll>>
#define goog(tno) cout<< "Case #" << tno << ": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define read(x) int x;cin>>x
void init_code(){ 
	
	fast_io;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout);
	#endif
}
// Code starts from here:







const int N=2e5+7; 
int multiples_ct[N];
int hsh[N];

int main(void)
{
	init_code();
    
    int t;
    cin>>t;
    while (t--)
    {
        string s;
        cin>>s;

        bool first = true;

        int op=0,cl=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(' )
            {
                op++;

            }
            else
            {
                cl++;
            }
        }

        //cout<<"ff"<<op<<" "<<cl<<endl;
         stack<char> stk;
         for(int i=0;i<s.size();i++)
         {
            if(s[i]=='(')
            {
                stk.push('(');
            }
            else
            {
               if(stk.size()==0)
               {
                 first=false;
                 break;
               }
               char x=stk.top();
               stk.pop();
               
            }
         }

         if(stk.size()==0)
          first= true;

        if(!first)
        {
            
            cout<<"YES"<<endl;
            int n=2*s.size();

            bool flag=1;

            for(int i=0;i<n;i++)
            {   
                if(flag)
                {
                    cout<<'(';
                    flag=0;
                }
                else
                {
                    cout<<')';
                    flag=1;
                }

            }
        }
        else
        {
            cout<<"NO";
            
        }
        cout<<endl;


    }
    

    
    return 0;
}