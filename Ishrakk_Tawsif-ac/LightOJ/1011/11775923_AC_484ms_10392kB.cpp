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

int cost[17][17],n,lim,dp[17][1<<17];

int call(int i,int mask)
{
    if(mask == lim) return 0;
    if(dp[i][mask] != -1) return dp[i][mask];

    int ans = 0;
    for(int j=0; j<n; j++)
    {
        //if(i == j) continue;
        if((!(mask & 1<<j))) ans = max(ans,call(i+1,(mask | 1<<j))+cost[i][j]);
    }
    return dp[i][mask] = ans;
}

int main()
{
    int tc;

    sf(tc);

    for(int tt=1; tt<=tc; tt++)
    {
        sf(n);

        lim = (1<<n)-1;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++) sf(cost[i][j]);
        }

        mem(dp,-1);
        int res = call(0,0);
        casepf(tt);
        pf("%d\n", res);
    }

    return 0;
}