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
#define intinf                  1e9
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

int ar[2005],dp[1005][1005],n;

int call(int i,int j)
{
    if(i>j) return 0;
    //if(i == j) return ar[i];

    if(dp[i][j]!= -1) return dp[i][j];

    //int ans1 = max(call(i+2,j,1-who) + ar[i],call(i+1,j-1,1-who)+ar[i]);
    //int ans2 = max(call(i,j-2,1-who) + ar[j],call(i+1,j-1,1-who)+ar[j]);
    int ans = -intinf;
    int ans1 = ar[i] - call(i+1,j);
    int ans2 = ar[j] - call(i,j-1);

    //cout<<i<<" " << j  << " " << ans1 << " " << ans2  << endl;
    //cout<<i<<" .......... " << j  << " " << ans1 << " " << ans2  << endl;

    ans=max(ans1,ans2);

    //ans = (!who)? ans = max(ans1,ans2) : ans = min(ans1,ans2);
//if(!who)cout<<i<<" " << j << " " << ans1 << " " << ans2 << " " << ans<<endl;
    return dp[i][j] = ans;
}

int main()
{
    int tc;

    sf(tc);

    while(tc--)
    {
        sf(n);
        int sum = 0;
        loop(i,0,n) {sf(ar[i]); sum += ar[i];}

        mem(dp,-1);
        int ans = call(0,n-1);//cout<<ans<<endl;
        pf("%d\n",ans);
    }
    return 0;
}