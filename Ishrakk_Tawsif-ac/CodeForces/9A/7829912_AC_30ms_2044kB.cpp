#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

int main()
{

    int a,b;

        while(scanf("%d %d", &a,&b)==2)
        {
            int temp = (6 - max(a,b))+1;
            int tt = gcd(6,temp);

            cout<<temp/tt<<"/"<<6/tt<<endl;
        }
    return 0;
}