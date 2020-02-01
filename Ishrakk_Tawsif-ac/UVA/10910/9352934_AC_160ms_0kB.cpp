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
#define mx                      5005
#define mod                     100000007
#define intinf                  2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())


int n,t,p,dp[101][101];

int call(int koyta,int koto)
{
    if(koyta == n && koto == t) return 1;
    if(koyta>n) return 0;
    if(dp[koyta][koto] != -1) return dp[koyta][koto];

        int ans=0;
        for(int i=p; i<=t; i++)
        {
            if(koto+i<=t) ans+=call(koyta+1,koto+i);
        }//cout<<ans<<endl;
   return dp[koyta][koto] = ans;
}

int main()
{
    int tc;

        sf(tc);

            loop(tt,1,tc+1)
            {
                sf(n); sf(t); sf(p);
                mem(dp,-1);
                cout<<call(0,0)<<endl;
            }

    return 0;
}