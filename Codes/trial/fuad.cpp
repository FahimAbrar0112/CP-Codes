#include<bits/stdc++.h>
using namespace std;



class Solution {
public:

    double eps=1e-1;

    int mySqrt(int x) {
        double lo=1,hi=  x,mid;

        while(hi-lo>eps)
        {
            mid=(lo+hi)/2;

                if(mid*mid<x)
                {
                    lo=mid;
                }
                else
                {
                    hi=mid;
                }

        }  

        cout<<lo<<" "<<hi<<endl;
        return hi;


    }
};



int main(void)
{
    
    Solution s;
    // s.mySqrt(4);
    // s.mySqrt(2);
    // s.mySqrt(8);
    s.mySqrt(2147395599);
    cout<<sqrt(2147395599)<<endl;

    return 0;
}