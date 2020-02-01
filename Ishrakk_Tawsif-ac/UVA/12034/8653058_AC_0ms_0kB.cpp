#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(var,till) for(int var=0; var<till; var++)
#define loop1(var,till) for(int var=1; var<=till; var++)
#define pb push_back
#define mx 2503
#define ll long long int
#define mp make_pair
#define mod 10056
#define fread(f) freopen (f,"r",stdin)
#define WRITE(f) freopen (f,"w",stdout)

ll arr[1001][1001],dp[1001];

ll call(int hr)
{
    if(hr == 0) return 1;
    if(dp[hr] !=- 1) return dp[hr];

        int ans=0;
        for(int i=hr,j=1; i>=1; i--,j++)
        {
            ans += (call(hr-j) * arr[hr][j])%mod;
        }
    return dp[hr]=(ans%mod);
}

int main()
{
    for(int i=0; i<=1000; i++)
    {
        for(int j=0; j<=i; j++)
        {
            if(j==0) arr[i][j]=1;
            else if(j==1) arr[i][j]=i;
            else arr[i][j]=(arr[i-1][j-1] + arr[i-1][j])%mod;
        }
    }

    int tc,n;

        sf(tc);

            memset(dp,-1,sizeof(dp));
            call(1000);
            loop1(tt,tc)
            {
                sf(n);
                pf("Case %d: %lld\n",tt,dp[n]);
            }
    return 0;
}