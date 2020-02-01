#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(till) for(int i=0; i<till; i++)
#define pb push_back
#define mx 1000005
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
int prime[mx],in;
vector <ll> ans;

void sieve()
{

    isprime[0]=isprime[1]=1;
    prime[0]=2;

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
void bfs(int s)
{
    dis[s]=0;
    vis[s]=1;
    queue<int>q;
    q.push(s);

        while(!q.empty())
        {
            int u=q.front(); q.pop();

                for(int i=0; i<graph[u].size(); i++)
                {
                    int v=graph[u][i];

                        if(!vis[v] && dis[v]>dis[u]+cost[u][v])
                        {
                            vis[v]=1;
                            dis[v]=dis[s]+cost[u][v];
                            q.push(v);
                        }
                }
        }
}
*/

/*
int row,col,ii,rr;
int dp[101][101],grid[101][101];


int call(int i, int j)
{
    if(j==col || i==row) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans;
//cout<<i<<" .. "<<j<<endl;system("pause");
        ans=grid[i][j]+max(call(i+1,j),call(i,j+1));
    return dp[i][j]=ans;
}
*/

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
/*
vector <int> v;

void pre_gen()
{
    for(int i=0; i<=in && v.size()<=100001; i++)
    {
        int temp=prime[i]+2;
        if(!isprime[temp] && temp%2!=0) v.pb(prime[i]);
    }
}*/


int dir_r[]={1,-1,-2,-2,1,-1,2,2};
int dir_c[]={-2,-2,1,-1,2,2,1,-1};

int main()
{

   int k,arr[103];

        while(sf(k) == 1)
        {
            loop(k)
            {
                sf(arr[i]);
            }
            int need=(k/2)+1,cnt=0,temp;
            sort(arr, arr+k);
                loop(need)
                {
                    if(arr[i]%2 == 0) cnt+=arr[i]/2;
                    else cnt+=(arr[i]/2)+1;
                }
            pf("%d\n", cnt);
        }
   return 0;
}