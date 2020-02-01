#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(var,till) for(int var=0; var<till; var++)
#define loop1(var,till) for(int var=1; var<=till; var++)
#define pb push_back
#define mx 103
#define ll long long int
#define mp make_pair
#define mod 100000007

int dir_r_8[]={-1,-1,-1,0,0,1,1,1};
int dir_c_8[]={-1,0,1,-1,1,-1,0,1};
int dir_r_4[]={-1,1,0,0};
int dir_c_4[]={0,0,-1,1};

string str;
ll dp[103][103][2],arr[103],n;

ll call(int lef,int rig,int player)
{
    if(lef>rig) return 0;
    if(dp[lef][rig][player] != -1) return dp[lef][rig][player];

        if(player == 0)
        {
            ll ans=0,ans2=LONG_MIN;

                for(int i=lef; i<=rig; i++)
                {
                    ans += arr[i];
                    ans2 = max(ans2, ans-call(i+1,rig,1-player));
                }

                ans=0;
                for(int i=rig; i>=lef; i--)
                {
                    ans += arr[i];
                    ans2 = max(ans2, ans-call(lef,i-1,1-player));
                }
            return dp[lef][rig][player] = ans2;
        }

        else if(player == 1)
        {
            ll ans=0,ans2=LONG_MIN;

                for(int i=lef; i<=rig; i++)
                {
                    ans += ((arr[i]));
                    ans2 = max(ans2, ans-call(i+1,rig,1-player));
                }

            ans=0;

                for(int i=rig; i>=lef; i--)
                {
                    ans += (arr[i]);
                    ans2 = max(ans2, ans-call(lef,i-1,1-player));
                }
            return dp[lef][rig][player] = ans2;
        }

}


int main()
{
    int tc;
        sf(tc);

            loop1(tt,tc)
            {
                sf(n);

                loop(i,n) scanf("%lld", &arr[i]);
                memset(dp,-1,sizeof(dp));
                pf("Case %d: %lld\n",tt,call(0,n-1,0));
            }
    return 0;
}