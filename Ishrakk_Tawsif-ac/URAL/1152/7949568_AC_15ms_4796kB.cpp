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

int cap,n,val[2005],wei[2005],dp[(1<<20)+5],arr[23],vis[17][(1<<16)+5],r,c,lim;

int dir_r[] = {1,1,1};
int dir_c[] = {-1,0,1};

int call(int mask)
{

    if(mask == lim) return 0;
    if(dp[mask]!=-1) return dp[mask];
    int ans=1<<30;
//cout<<ans<<endl;
        for(int i=0; i<n; i++)
        {
            if(mask & (1<<i)) continue;
            int temp=0;
            int j=i+1,k=i-1;    if(j>=n) j=0; if(k<0) k=n-1;//cout<<i<<" "<<j<<" "<<k<<endl;
            for(int l=0; l<n; l++){
                if(l==i || l==j || l==k) continue;
                if(!(mask & (1<<l))) temp+=arr[l];
            }//cout<<temp <<endl;
           ans = min(ans, call(mask | (1<<i) | (1<<j) | (1<<k))+temp);
        }//cout<<ans<<endl;
   return dp[mask]=ans;
}

int main()
{
    int tc;

    //while(sf(tc) == 1)
    //{
        //for(int tt=1; tt<=tc; tt++)
        //{
            memset(dp,-1,sizeof(dp));
            sf(n);
            loop(n){
                sf(arr[i]);
            }
            lim=(1<<n)-1;//cout<<lim<<endl;
            pf("%d\n",call(0));
        //}
    //}
    return 0;
}