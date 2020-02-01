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
#define mod 1000000007

int dir_r_8[]={-1,-1,-1,0,0,1,1,1};
int dir_c_8[]={-1,0,1,-1,1,-1,0,1};
int dir_r_4[]={-1,1,0,0};
int dir_c_4[]={0,0,-1,1};

int wei[1003],capa[1003],dp[1003][3003],n,cap;

int ks(int i,int w)
{
    if(i>n) return 0;
    if(w==0) return 0;
    if(dp[i][w]!=-1) return dp[i][w];

        if(wei[i]<=w)dp[i][w] = max(ks(i+1,w),ks(i+1,min(capa[i],w-wei[i]))+1);
        else dp[i][w]=ks(i+1,w);
        //cout << i << " " << w << " " << dp[i][w]<<endl;
    return dp[i][w];
}

int main()
{
    //int n;
        while(sf(n) == 1 && n!=0)
        {
            loop1(i,n) scanf("%d %d",&wei[i],&capa[i]);
            int ans=INT_MIN;
            memset(dp,-1,sizeof(dp));
            for(int i=1; i<=n; i++)
            {
                cap = capa[i];
                ans = max(ans,ks(i+1,cap)+1);//system("pause");
            }cout<<ans<<endl;
        }
}