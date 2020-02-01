#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(var,till) for(int var=0; var<till; var++)
#define loop1(var,till) for(int var=1; var<=till; var++)
#define pb push_back
#define mx 100000005
#define ll long long int
#define mp make_pair
#define mod 1000000009


int coins[7];
ll dp[6][7493];

ll call(int i,int cap)
{
    if(i==0)
    {
        if(cap==0) return 1;
        return 0;
    }
    if(cap==0) return 1;
    if(dp[i][cap]!=-1) return dp[i][cap];

        ll ans;

            if(cap<coins[i])
                ans=call(i-1,cap);
            else
                ans=call(i-1,cap)+call(i,cap-coins[i]);
//cout<<ans<<endl;
    return dp[i][cap]=ans;
}

int main()
{
    coins[1]=1; coins[2]=5; coins[3]=10, coins[4]=25, coins[5]=50;
        int n;

            memset(dp,-1,sizeof(dp));
            while(sf(n) == 1)
            {
                cout<<call(5,n)<<endl;
            }
   return 0;
}