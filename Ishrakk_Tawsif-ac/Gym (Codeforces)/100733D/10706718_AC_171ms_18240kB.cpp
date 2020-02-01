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

int dx4[] = {-1,0,0,1};
int dy4[] = {0,-1,1,0};

int ar[1000005],dp[1000005],n;


int call(int i)
{
    if(i>=n) return 0;
    if(dp[i] != -1) return dp[i];

    int ans1,ans2;

    ans1 = call(i+3) + ar[i];
    ans2 = call(i+1);

    return dp[i] = max(ans1,ans2);
}

int main()
{
    //int n;
    sf(n);

    loop(i,0,n) sf(ar[i]);

    mem(dp,-1);
    pf("%d\n",call(0));

    return 0;
}