#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(var,till) for(int var=0; var<till; var++)
#define loop1(var,till) for(int var=1; var<=till; var++)
#define pb push_back
#define mx 1003
#define ll long long int
#define mp make_pair
#define mod 1000000

int coin[103],dp[103][50003],n,in,sum;

int call(int pos,int mon)
{
    if (pos<0) return abs((sum-mon)-mon);
    if(dp[pos][mon] != -1) return dp[pos][mon];

        int temp=0,ans=INT_MAX,ans2=INT_MAX,temp2=0;

            ans = min(ans,call(pos-1,mon-coin[pos]));
            ans = min(ans,call(pos-1,mon));

    return dp[pos][mon] = ans;
}

int main()
{
    int tc;

        sf(tc);

            loop1(tt,tc)
            {
                sf(n);
                sum=0;

                    loop(i,n) {sf(coin[i]); sum+=coin[i];}

                    sort(coin,coin+n);
                    memset(dp,-1,sizeof(dp));
                    cout<<call(n-1,sum)<<endl;
            }
     return 0;
}