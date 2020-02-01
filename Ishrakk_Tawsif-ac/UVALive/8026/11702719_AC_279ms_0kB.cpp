#include<bits/stdc++.h>
using namespace std;

#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case #%d: ",nn)
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


int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

struct ST
{
    double a,b,c;
};

ST ar[13];
double dp[13][15005],visited[13][15005];
int n;

double func(double t,int pos)
{
    t/=5;

    return (((ar[pos].a)*(t*t)) + (ar[pos].b * t) + ar[pos].c);
}

double call(int i,int t)
{
    if(i>=n) return 0.0;
    if(visited[i][t]) return dp[i][t];
    visited[i][t] = 1;

    double ans = 0.0;

    for(int j = 0; j<=t; j++)
    {
        ans = max(ans,call(i+1,t-j)+func(j,i));
    }
    return dp[i][t] = ans;
}

int main()
{
    int t;

    while(~scanf("%d %d", &n,&t))
    {

        for(int i=0; i<n; i++)
        {
            cin>> ar[i].a>> ar[i].b>> ar[i].c;
        }
        mem(visited,0);
        pf("%.9f\n", call(0,t*5)/n*1.0);
    }

    return 0;
}