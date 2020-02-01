#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(till) for(int i=0; i<till; i++)
#define pb push_back
#define mx 10005
#define ll long long int
#define mp make_pair
#define mod 10000007

/*
creating iterator to iterate a map ...
typedef std::map<string,int>::iterator it_type;
for(it_type iterator = fruits.begin(); iterator != fruits.end(); iterator++)
*/

/*int knapsack(int i,int w)
{
    if(i<0) return 0;
    if(dp[i][w]!=-1) return dp[i][w];

        if(w-wei[i]>=0)dp[i][w] = max(ks(i-1,w),ks(i-1,w-wei[i])+val[i]);
        else dp[i][w]=ks(i-1,w);
        //cout << i << " " << w << " " << dp[i][w]<<endl;
    return dp[i][w];
}*/

vector <int> graph[mx];
vector <int> graph2[mx];

int cap,n,val[2005],wei[2005],dp[17][(1<<16)+5],arr[17][(1<<16)+5],vis[17][(1<<16)+5],r,c,lim;

int dir_r[] = {1,1,1};
int dir_c[] = {-1,0,1};

int call(int pos,int mask)
{
//cout<<ans<<endl;
    if(mask == lim) return 0;
    int &ans=dp[pos][mask];
    if(ans!=-1) return ans;
   // if(dp[pos][mask]!=-1) return dp[pos][mask];
    ans=0;

        for(int i=0; i<n; i++)
        {
            if(!(mask & (1<<i)))
                ans=max(ans,call(pos+1,mask | (1<<i))+arr[pos][i]);
        }//cout<<ans<<endl;
   return dp[pos][mask]=ans;
}

int main()
{
    int tc;

    while(sf(tc) == 1)
    {
        for(int tt=1; tt<=tc; tt++)
        {
            memset(dp,-1,sizeof(dp));
            sf(n);
            loop(n){
                for(int j=0; j<n; j++) sf(arr[i][j]);
            }
            lim=(1<<n)-1;//cout<<lim<<endl;
            pf("Case %d: %d\n", tt,call(0,0));
        }
    }
    return 0;
}