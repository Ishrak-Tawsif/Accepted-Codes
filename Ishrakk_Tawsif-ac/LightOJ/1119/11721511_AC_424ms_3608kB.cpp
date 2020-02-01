#include<bits/stdc++.h>
using namespace std;

int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case %d: ",nn)
#define out(nn)                 cout <<nn <<endl
#define loop(var,start,till)    for(int var=start; var<till; var++)
#define pb                      push_back
#define mem(a,b)                memset(a,b,sizeof(a))
#define mp                      make_pair
#define ll                      long long int
#define inf                     2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      20000005
#define mod                     1000000007

int ar[15][15],n,dp[15][1<<15],lim;

int call(int pos,int mask)
{
    if(mask == lim) return 0;
    if(dp[pos][mask] != -1) return dp[pos][mask];

    int ans = inf,temp = 0;

    for(int i=0; i<n; i++)
    {
        int curcost=inf;
        if(!(mask & 1<<i))
        {
            curcost = ar[i][i];
            for(int j=0; j<n; j++)
            {
                if(i == j) continue;
                if(mask & 1<<j)curcost += ar[i][j];
            }
            curcost += call(pos+1,mask | 1<<i);
        }
        ans = min(ans,curcost);
    }
    return dp[pos][mask] = ans;
}

int main()
{
    int tc;

    sf(tc);

    for(int tt=1; tt<=tc; tt++)
    {
        sf(n);

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++) sf(ar[i][j]);
        }
        mem(dp,-1);
        lim = (1<<n)-1;
        casepf(tt);
        pf("%d\n", call(0,0));
    }

    return 0;
}