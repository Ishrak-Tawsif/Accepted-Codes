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

ll ar[100005],temp,dp[100005];
int n,ind[4];

ll call(int i)
{
    if(i>=n) return 0;
    if(dp[i] != -1) return dp[i];

    ll temp=0,ans[3];
    ans[0]=ans[1]=ans[2]=0;
    for(int j=i,k=0; /*j<n &&*/ k<3; j++,k++)
        {
            if(j<n)temp+=ar[j];
            ans[k] = call(i+ind[k]) + (temp);
        }

    return dp[i] = max(ans[0],max(ans[1],ans[2]));
}

int main()
{
    int tc;

    scanf("%d", &tc);

    ind[0]=2,ind[1]=4,ind[2]=6;
    while(tc--)
    {
        sf(n);
        for(int i=0; i<n; i++) {scanf("%lld", &ar[i]);};
        mem(dp,-1);
        cout<<call(0)<<endl;
    }

    return 0;
}