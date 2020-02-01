#include<bits/stdc++.h>
using namespace std;

bool istriangle(int a, int b, int c)
{
    if(a+b>c && b+c>a && a+c>b) {
        if((abs(a-b)<c) && (abs(a-c)<b) && abs(c-b)<a) return 1;
    }
    return 0;
}

bool isdtriangle(int a,int b, int c)
{
    if(a==b+c || b==a+c || c==a+b || a==0 || b==0 ||c==0) return 1;
    return 0;
}

int main()
{

    int a,b,c,d;

        while(scanf("%d%d%d%d",&a,&b,&c,&d) == 4)
        {
            if(istriangle(a,b,c) || istriangle(a,b,d) || istriangle(b,c,d) || istriangle(a,c,d)) {
                printf("TRIANGLE\n");
            }
            else if(isdtriangle(a,b,c) || isdtriangle(a,b,d) || isdtriangle(b,c,d) || isdtriangle(a,c,d)) printf("SEGMENT\n");
            else printf("IMPOSSIBLE\n");
        }
}