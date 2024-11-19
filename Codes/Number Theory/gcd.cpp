  #include<bits/stdc++.h>
  using namespace std;
   
  /*
  
    a*b = gcd*lcm
    gcd= min power of the primes 
    lcm= max power of the primes
  
  */

 int gcd(int a,int b)
 {
     if(a%b==0)
      return b;

    return gcd(b,a%b);   


 }
  
  int main(void)
  {
      
      cout<<gcd(12,18)<<endl;
      cout<< (12*18)/gcd(12,18)<<endl;
  
  
      return 0;
  }