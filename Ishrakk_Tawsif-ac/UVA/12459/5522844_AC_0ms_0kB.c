#include<stdio.h>
int main()
{
    long long in,num1,num2,i,sum;
    while(scanf("%lld",&in)==1 && in)
    {
        num1=0;
        num2=1;
        for(i=1; i<=in; i++)
        {
            sum=num1+num2;
            num1=num2;
            num2=sum;
        }
        printf("%lld\n",sum);
    }

    return 0;
}
