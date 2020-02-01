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
ll dp[103][103];

ll call(int i,int j)
{

    if(j<=i) return 0;
    if(dp[i][j] != -1) return dp[i][j];

        ll ans=0,ans1=0,ans2=0;

        if(str[i] == str[j]) ans=call(i+1,j-1);
        else
        {
            ans=min(call(i+1,j)+1,call(i,j-1)+1);
        }

    return dp[i][j]=ans;
}

int main()
{
    int tc;
        sf(tc);

            loop1(tt,tc)
            {
                cin>> str;
                memset(dp,-1,sizeof(dp));
                pf("Case %d: %lld\n",tt,call(0,str.length()-1));
            }
    return 0;
}