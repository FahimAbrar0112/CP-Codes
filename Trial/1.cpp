#include <bits/stdc++.h>
using namespace std;

int main(void)
{

     string s = "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFT";
     int ct=0;
     for(auto val:s)
     {
          if(val=='F')
           ct++;
     }
     cout<<ct<<endl;
}