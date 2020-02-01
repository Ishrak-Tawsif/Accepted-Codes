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
#define inf                     2e9
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      20000005
#define mod                     1000000007


int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

int ar[105],dp[105][105];

int call(int i,int j)
{
    if(i>j) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int ans1 = -inf,ans2 = -inf,sum1=0,sum2=0;

    for(int k=i; k<=j; k++) {sum1 += ar[k]; ans1 = max(ans1,sum1 - call(k+1,j));}
    for(int k=j; k>=i; k--) {sum2 += ar[k]; ans2 = max(ans2,sum2 - call(i,k-1));}
//cout<<i << " " << j << " " << ans1 << " " << ans2 << endl;
    return dp[i][j] = max(ans1,ans2);
}

int main()
{
    int n;

    while(sf(n))
    {
        if(!n) break;

        for(int i=0; i<n; i++) sf(ar[i]);
        mem(dp,-1);
        pf("%d\n", call(0,(n-1)));
    }
    return 0;
}