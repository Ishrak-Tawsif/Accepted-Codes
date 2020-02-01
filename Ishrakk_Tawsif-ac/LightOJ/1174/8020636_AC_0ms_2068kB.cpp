#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(var,till) for(int var=0; var<till; var++)
#define loop1(var,till) for(int var=1; var<=till; var++)
#define pb push_back
#define mx 47001
#define ll long long int
#define mp make_pair
#define mod 1000000009

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

bitset<mx>isprime;
ll prime[mx],in;
vector <ll> ans;

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
                    if(!isprime[i] && (i%2)!=0) prime[++in]=(ll)i;
                    //else cnt[i]=cnt[i-1];
            }
}


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

vector <int> graph[103];
int vis[2][103],dis[2][103];

void bfs(int s,int type) ///type 0 for bfs from source and 1 for from destination
{
    dis[type][s]=0;
    vis[type][s]=1;
    queue<int>q;
    q.push(s);

        while(!q.empty())
        {
            int u=q.front(); q.pop();

                for(int i=0; i<graph[u].size(); i++)
                {
                    int v=graph[u][i];

                        if(!vis[type][v] && dis[type][v]>dis[type][u]+1)
                        {
                            vis[type][v]=1;
                            dis[type][v]=dis[type][u]+1;
                            q.push(v);
                        }
                }
        }
}


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
int main()
{

   int tc,node,edge,u,v,source,desti;
        sf(tc);
            loop1(tt,tc)
            {
                scanf("%d %d", &node, &edge);

                for(int i=0; i<103; i++) graph[i].clear();

                    loop(i,edge)
                    {
                        scanf("%d %d", &u, &v);
                        graph[u].pb(v);
                        graph[v].pb(u);
                    }
                    scanf("%d %d", &source, &desti);
                    for(int i=0; i<103; i++){dis[0][i]=INT_MAX; dis[1][i]=INT_MAX;vis[0][i]=0;vis[1][i]=0;}

                    bfs(source,0);
                    bfs(desti,1);

                        int max_=INT_MIN;

                            loop(i,node)
                            {
                                max_=max(max_,(dis[0][i]+dis[1][i]));
                            }
                            pf("Case %d: %d\n", tt,max_);
            }

   return 0;
}