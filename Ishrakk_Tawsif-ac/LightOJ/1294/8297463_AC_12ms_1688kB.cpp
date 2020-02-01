#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(var,till) for(int var=0; var<till; var++)
#define loop1(var,till) for(int var=1; var<=till; var++)
#define pb push_back
#define mx 2503
#define ll long long int
#define mp make_pair
#define mod 100000007

///hints

/*
lets n=6 and m=3
so : -1-2-3+4+5+6
now : (-1+4)=3; (-2+5)=3; (-3+6)=3
so we will always get m and how many time we will get m.Thats will be n/2 times.
so ans will be m*(n/2).
*/

int main()
{
    ll n,m;
    int tc;
            sf(tc);
                loop1(tt,tc)
                {
                    scanf("%lld %lld", &n,&m);
                    pf("Case %d: %lld\n",tt,(n/2)*m);
                }
    return 0;
}