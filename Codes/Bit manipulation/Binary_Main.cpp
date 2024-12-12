#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
const int INF = INT_MAX;

/*
    7 6 5 4 3 2 1 0 th bit
    1 0 1 1 1 0 1 1  =>binary num
    MSB <-------- LSB
    odd binary =>last bit 1
    even binary => last bit 0

    set means 1
    unset means 0

     1    0    0    1
     3rd  2nd  1st  0th

    3rd and 0th bit are set
    1st and 2nd bit are unset
    there are 2 set and 2 unset bits present


    Check a bit of a number is set or not:
    1 0 1
      check 1st bit is set or not
      to do so use a number that has only
      one set bit on 1st bit
      then and (&)  them.

      bool SetOrNot(int n,int ind)
      {
         //return 1 if set
         //return 0 if unset
        return ((n &(1<<ind))!=0);
      }

    101
  & 010
  ------
    000
    =0
    So, 1st bit unset



    111
 &  010
----------
    010
    !=0 non zero
    So, 1st bit is set

    To check ith bit of a number is set or not
    take a number having only the ith bit set and other digits are unset
    then and operation them .

    To take the number that has only one set bit
     1<<i
    say 1st bit set :
    1<<1 => 10
         =>010

    //Set a bit:

    int setBit(int n,int i)
    {
        return (n |(1<<i)) ;
    }

    How to set ith bit of a number:
     (num |  1<<i)

     1001  make 1st bit set
   | 0010
--------------
     1011


    //Unset a bit :

    int unsetBit(int n,int ind)
    {
        return   (n & (~(1<<ind))) ;
    }

    How to unset ith bit of a number:
     only ith bit will be zero and other bit will be 1
     ~(1<<i)

     1001
      unset 3rd bit
      1<<3 => 1000
      ~(1<<3 ) =>  ~(0001000) => 1110111

     S0,
      1001 &  (  ~(1<<3)  )


        1001
     &  0111
     --------
        0001





     Toggle a bit:
      1 => 0
      0 => 1
     How?  XOR operation
      a^(1<<i)

     1001  toggle 2nd bit
     1<<2 => 0100

     1001 ^ 0100 => 1101

     int Toggle_A_Bit(int n,int i)
     {
        return (n^(1<<i));
     }



    Count how many set bits are there:

     int ct=0;
     for(int i=31;i>=0;i--)
     {
        if( (a &(1<<i)) !=0 )
         ct++;
     }



*/

int countSetBit_method1(int n)
{
    int ct = 0;
    for (int i = 31; i >= 0; i--)
    {
        if ((n >> i) & 1)
            ct++;
    }
    cout << ct << endl;
    return ct;
}

int countSetBit_method2(int n)
{
    int ct = 0;
    for (int i = 31; i >= 0; i--)
    {
        if ((n & (1 << i)) != 0)
            ct++;
    }
    return ct;
}

long long countSetBit_method3(long long x)
{
    long long ct = 0;

    while (x >= 1)
    {
        if (x & 1)
        {
            ct++;
        }

        x >>= 1;
    }
    return ct;
}

int countSetBit_method4(int n)
{
    return __builtin_popcount(n);
    // for int

    // for long use:
    // return __builtin_popcountll(n);
}

bool SetOrNot(int n, int ind)
{
    // return 1 if set
    // return 0 if unset
    return ((n & (1 << ind)) != 0);
}

int setBit(int n, int i)
{
    return (n | (1 << i));
}

int unsetBit(int n, int ind)
{
    return (n & (~(1 << ind)));
}

int Toggle_A_Bit(int n, int i)
{
    return (n ^ (1 << i));
}

void printBinary(int n)
{
    for (int i = 31; i >= 0; i--)
    {
        cout << ((n >> i) & 1);
    }
    cout << endl;
}

int main(void)
{

    cout << ((11 >> 2) & 1) << endl;
    printBinary(11);
    // printBinary(-11);  // 2's complement = 1's complement+1
    printBinary(setBit(11, 2));
    printBinary(unsetBit(11, 1));
    cout << SetOrNot(11, 2) << endl;
    cout << SetOrNot(11, 3) << endl;

    printBinary(Toggle_A_Bit(11, 3));
    printBinary(Toggle_A_Bit(11, 2));

    cout << countSetBit_method3(11);
    cout << countSetBit_method3(0);
    cout << countSetBit_method3(1);

    cout<<endl;

    return 0;
}