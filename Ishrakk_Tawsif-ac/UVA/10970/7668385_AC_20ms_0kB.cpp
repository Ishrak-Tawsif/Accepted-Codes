#include <stdio.h>
int main()
{
    long long int a,b;
    while(scanf("%lld %lld", &a, &b)==2){
        printf("%lld\n", (a*b)-1);
    }
}