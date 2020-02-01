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
#define mod 100000007

/*
creating iterator to iterate a map ...
typedef std::map<string,int>::iterator it_type;
for(it_type iterator = fruits.begin(); iterator != fruits.end(); iterator++)
*/

//ll val[1001],coin [1001],dp[1001][1001],n;

///knapsack
/*int ks(int i,int w)
{
    if(i<0) return 0;
    if(dp[i][w]!=-1) return dp[i][w];

        if(w-wei[i]>=0)dp[i][w] = max(ks(i-1,w),ks(i-1,w-wei[i])+val[i]);
        else dp[i][w]=ks(i-1,w);
        //cout << i << " " << w << " " << dp[i][w]<<endl;
    return dp[i][w];
}*/

///struct
/*struct d
{
    int h,w,nn;

        bool operator <(const d &x) const{
            if(w==x.w) return h<x.h;
            return w<x.w;
        }
};*/

///sieve
/*
bitset<mx>isprime;
int prime[5761459],in;
//vector <ll> ans;

void sieve()
{

    isprime[0]=isprime[1]=1;
    prime[0]=2;
    //for(int i=4; i<mx; i+=2) isprime[i]=1;
            for(int i=3; i*i<mx; i+=2)
            {
                if(!isprime[i]) for(int j=i*i; j<mx; j+=i) isprime[j]=1;
            }
            //cnt[2]=1;
            in=0;
            for(int i=3; i<mx; i+=2){
                    if(!isprime[i] && (i%2)!=0) prime[++in]=i;
                    //else cnt[i]=cnt[i-1];
            }
}

*/
//int arr[101][101],dp[101][101],n,m;


///power function
/*ll ipow(ll base,ll pow)
{
    ll res=base;

        while(pow--) res*=base;
    return res;
}*/


///dfs
/*
vector <int> graph[19];
ll cost[19][19];
int dis[19],vis[19];

int dfs(int s)
{
    if(!vis[s]){
        vis[s]=1;
        for(int i=0; i<graph[s].size(); i++){
            int v=graph[s][i];
                if(!vis[v] && dis[v]>dis[s]+cost[s][v]){
                    dis[v]=dis[s]+cost[s][v];
                    dfs(v);
                }
        }
    }
}
*/

/*
vector <int> graph[5003];
int vis[5003],dis[2][5003],cost[5003][5003];


void bfs(int s,int d) ///type 0 for bfs from source and 1 for from destination
{
    dis[0][s]=0;
    vis[s]=1;
    queue<int>q;
    q.push(s);

        while(!q.empty())
        {
            int u=q.front(); q.pop();
            if(u==d) break;
                for(int i=0; i<graph[u].size(); i++)
                {
                    int v=graph[u][i];//cout<<u<<" "<<v<<" "<<dis[0][v]<<" "<<dis[0][u]<<" "<<cost[u][v]<<endl;

                        if(dis[0][v]>dis[0][u]+cost[u][v])
                        {
                            dis[1][v]=dis[0][v];//cout<<v<<endl;
                            vis[v]=1;
                            dis[0][v]=dis[0][u]+cost[u][v];
                            q.push(v);
                        }
                        else if(dis[1][v]>dis[0][u]+cost[u][v] && dis[0][v]<dis[0][u]+cost[u][v])
                        {
                            dis[1][v]=dis[0][v]+cost[u][v];cout<<v<<endl;
                            q.push(v);
                        }
                }
        }
}*/


/*
ll arr[21],dp[1<<17][21],in=-1,len,lim,k,base;

///bitmask dp

ll bitmask(int num,int mask)
{
    if(mask==lim){if(num%k == 0) return 1; else return 0;}
    if(dp[mask][num]!=-1) return dp[mask][num];

        ll ans=0;
        for(int i=0; i<=in; i++){
            if(!(mask & 1<<i))
                ans+=(bitmask(((num*base)+arr[i])%k,(mask|(1<<i))));
        }
    return dp[mask][num]=ans;
}
*/

///number of divisor
/*
unsigned ll div(unsigned ll n)
{
    unsigned ll cnt=0;
    for(int i=0; (unsigned ll)prime[i]*prime[i]<=n && i<=in; i++)
    {
        if(n%prime[i]==0){
            cnt++;

                while(n%prime[i] == 0) n/=(unsigned ll)prime[i];
        }
    }
    if(n!=1) cnt++;

    return cnt;
}
*/


int dp[101][10001],coins[101],n,k;

int call()
{
     //for(int i=0; i<=k; i++) dp[0][i]=0;
    dp[1][0]=1;
    for(int i=1; i<=k; i++) {
           if(i>=coins[1]) dp[1][i]=dp[1][i-coins[1]];
           else dp[1][i]=0;
    }

        for(int  i=2; i<=n; i++)
        {
            dp[i][0]=1;
            for(int j=1; j<=k; j++)
                {
                    if(j>=coins[i])dp[i][j]=((dp[i-1][j]%mod)+(dp[i][j-coins[i]])%mod)%mod;
                    else dp[i][j]=(dp[i-1][j])%mod;
                }
        }
}

int main()
{
   int tc;
   sf(tc);

        for(int tt=1; tt<=tc; tt++)
        {
            scanf("%d %d", &n, &k);
            loop1(i,n) scanf("%d", &coins[i]);
            //loop1(i,n) scanf("%lld", &numofcoins[i]);

            //memset(dp,-1,sizeof(dp));
            sort(coins,coins+(n+1));//for(int i=1; i<=n; i++)cout<<coins[i];
            call();//cout<<n<<" "<<k<<endl;
            /*for(int i=1; i<=n; i++){cout<<i<<endl;
                for(int j=0; j<=k; j++) cout<<dp[i][j]<<" ";
                cout<<endl;
            }*/
            pf("Case %d: %d\n", tt, dp[n][k]%mod);
        }
   return 0;
}