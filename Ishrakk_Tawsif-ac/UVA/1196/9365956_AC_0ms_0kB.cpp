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

int n,dp[103][103],cnt[103][103];


int call(int i,int j)
{//cout<<i<<" " <<j << endl;
    if(i<1 || j<1) return 0;
    if(dp[i][j] != -1) return dp[i][j];

        int ans1=0;

            ans1 = max(call(i-1,j),call(i,j-1));
            ans1 += cnt[i][j];

    return dp[i][j] = ans1;
}

int main()
{
    int u,v;
    //WRITE("test.txt");
    while(sf(n) == 1 && n)
    {
        for(int i=0; i<102; i++)
        {
            for(int j=0; j<102; j++)
            {
                dp[i][j] = -1;
                cnt[i][j] = 0;
            }
        }

        loop(i,1,n+1)
        {
            sf(u); sf(v);
            cnt[u][v]++;
        }

        for(int i=1; i<=100; i++)
        {
            for(int j=1; j<=100; j++)
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                dp[i][j] += cnt[i][j];
            }
        }
        pf("%d\n",dp[100][100]+1);
    }
    pf("*\n");
    return 0;
}