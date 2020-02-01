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


string a,b;
int dp[5005][5005];

int call(int i,int j)
{
    if(i>=a.size() || j>=b.size()) return 0;
    if(dp[i][j]!=-1) return (dp[i][j])%mod;

    int ans=0;

    if(a[i] == b[j])
    {
        ans = ((call(i+1,j+1))%mod  + 1)%mod;
    }
    ans = ((ans%mod) + (call(i,j+1))%mod)%mod;
    return dp[i][j] = (ans)%mod;
}

int main()
{
    cin>> a>> b;
    memset(dp,-1,sizeof(dp));

        int res=0;

            for(int i=0; i<a.size(); i++)
            {
                res = (((res)%mod + (call(i,0))%mod)%mod)%mod;
            }cout<<(res)%mod<<endl;
    return 0;
}