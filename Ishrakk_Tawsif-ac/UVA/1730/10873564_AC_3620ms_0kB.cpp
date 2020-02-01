#include<bits/stdc++.h>
using namespace std;

#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case %d:\n",nn)
#define out(nn)                 cout <<nn <<endl
#define loop(var,start,till)    for(int var=start; var<till; var++)
#define pb                      push_back
#define mem(a,b)                memset(a,b,sizeof(a))
#define mp                      make_pair
#define ll                      long long int
#define intinf                  7e18
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      20000005
#define mod                     1000000007


int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

ll sum[mx];

void pre_gen()
{
    for(ll i=1; i<mx; i++)
    {
        for(ll j=i; j<mx; j+=i) sum[j] += i;
    }

    for(ll i=1; i<mx; i++) sum[i] = sum[i] + sum[i-1];
}

int main()
{
    pre_gen();

    ll n;

    while(scanf("%lld", &n) == 1 && n)
    {
        pf("%lld\n", sum[n]-1);
    }
    return 0;
}