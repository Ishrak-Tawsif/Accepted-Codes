#include <bits/stdc++.h>
using namespace std;

#define limit 16383
vector <int> fs,sn;

int ipow(int base,int pow)
{
    int res = 1;

    while(pow --) res *= base;

    return res;
}

int main()
{
    int get1,get2;
    printf("?");
    for(int i=1; i<=100; i++) printf(" %d", i);
    printf("\n");
    fflush(stdout);
    scanf("%d", &get1);
    printf("?");
    for(int i=1; i<=100; i++) printf(" %d", (i<<7));
    printf("\n");
    fflush(stdout);
    scanf("%d", &get2);

    int res = 0;
    for(int i=7; i<=13; i++)
    {
        if(!(get1 & (1<<i)))
        {

        }
        else res += ipow(2,i);
    }

    for(int i=0; i<=6; i++)
    {
        if(!(get2 & (1<<i)))
        {
            ///0
        }
        else res += ipow(2,i);
    }
    printf("! %d\n", res);
    fflush(stdout);
    return 0;
}