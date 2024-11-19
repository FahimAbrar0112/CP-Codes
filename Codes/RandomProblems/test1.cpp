#include<stdio.h>
#include<math.h>

int main()
{

  float a,b,c,s;
  printf("Enter the three sides of  riangle:");
scanf("%f %f %f",&a,&b,&c);
if(a!=b || b!=c || c!=a)
    printf("Not equilateral");
else{
        s=(a+b+c)/2;
        if(sqrt(s*(s-a)*(s-b)*(s-c))>30.0)
        printf("Perfect"); 
        else
        printf("Not large enough");
    }    

}
