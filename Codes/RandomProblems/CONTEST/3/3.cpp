#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;



int main(void)
{   
    multiset<int>s;
    s.insert(3); 
    s.insert(3);  
    s.insert(2); 
    s.insert(5); 
    s.insert(5); 

    auto it = s.end();
    cout<<*it<<endl;
    

    



    return 0;
}