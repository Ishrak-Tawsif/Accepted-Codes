#include<bits/stdc++.h>
using namespace std;

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
#define intinf                  2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      100005
#define mod                     1000000007


int dx[8] = {1,-1,0,0,-1,-1,1,1};
int dy[8] = {0,0,-1,1,-1,1,-1,1};

int dirr[] = {-1,-1,0,0,1,1};
int dirc[] = {0,1,-1,1,-1,0};


int n,m,k;
ll dp[53][53][53];

ll call(int seq,int cur,int tot) ///tot koyta , cur koyta nilam , seq koyta
{
    if(seq>k) return 0;
    if(tot>n) return 0;

    if(seq == k && tot == n) return 1;

    if(dp[seq][cur][tot] != -1) return dp[seq][cur][tot];

        ll ans=0;
        for(int j=1; j<=m; j++)
        {
            if(tot+j<=n) ans += call(seq+1,j,tot+j);
        }

    return dp[seq][cur][tot] = ans;
}

int main()
{
	while(scanf("%d %d %d", &n,&k,&m) == 3)
    {
        mem(dp,-1);
        ll ans = call(0,0,0);
        pf("%lld\n", ans);
    }

	return 0;
}