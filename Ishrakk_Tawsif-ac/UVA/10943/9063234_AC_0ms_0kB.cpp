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

int dir_r_8[]={-1,-1,-1,0,0,1,1,1};
int dir_c_8[]={-1,0,1,-1,1,-1,0,1};
int dir_r_4[]={-1,1,0,0};
int dir_c_4[]={0,0,-1,1};

int n,k;

/*int call(int pos)
{
    if(dp[pos] != -1) return dp;

        int ans=0;
        for(int i=1; i<=k; i++)
        {
            for(int i=1; i<=n; i++) ans += call(i);
        }

}*/

ll arr[301][301];

int main()
{
    for(int i=0; i<=301; i++)
    {
        for(int j=0; j<=i; j++)
        {
            if(j == 0) arr[i][j]=1;
            else if(j == 1) arr[i][j]=i;
            else arr[i][j]= ((((arr[i-1][j-1])%mod) + ((arr[i-1][j])%mod))%mod);
        }
    }

    while(scanf("%d %d", &n,&k) == 2)
    {
        if(n==0 && k==0) break;
        pf("%lld\n", (arr[n+k-1][k-1])%mod);
    }
    return 0;
}