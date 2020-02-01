#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(var,till) for(int var=0; var<till; var++)
#define loop1(var,till) for(int var=1; var<=till; var++)
#define pb push_back
#define mx 100000005
//#define ll long long int
#define mp make_pair
#define mod 100000007


int dp[53][23][1003],coins[53],numofcoins[53],n,k;

int call(int i,int j,int cap)
{
//cout<<cap<<endl;
    if(i>n)
    {
        if(cap==0) return 1;
        return 0;
    }
    if(cap==0) return 1;
    if(cap<0) return 0;
    if(dp[i][j][cap]!=-1) return dp[i][j][cap]%mod;

        int ans=0,temp=0;

        if(j+1<=numofcoins[i] && cap-coins[i]>=0) ans=(call(i,j+1,cap-coins[i]))%mod;
        temp=(call(i+1,0,cap))%mod;

    //cout<<i<<" "<<j<<" "<<cap<<" "<<ans<<endl;
    return dp[i][j][cap]=(ans+temp)%mod;
}


int main()
{
   int tc;
   sf(tc);

        for(int tt=1; tt<=tc; tt++)
        {
            scanf("%d %d", &n, &k);
            loop1(i,n) scanf("%d", &coins[i]);
            loop1(i,n) scanf("%d", &numofcoins[i]);

            memset(dp,-1,sizeof(dp));
            pf("Case %d: %d\n", tt, (call(0,0,k)));
        }

   return 0;
}