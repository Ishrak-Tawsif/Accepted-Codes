#include <bits/stdc++.h>
using namespace std;

int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

/*#pragma comment(linker,"/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case %d: ",nn)
#define out(nn)                 cout <<nn <<endl
#define loop(var,start,till)    for(int var=start; var<till; var++)
#define loop1(var,start,till)   for(int var=start; var<=till; var++)
#define pb                      push_back
#define mem(a,b)                memset(a,b,sizeof(a))
#define mp                      make_pair
#define ll                      long long int
#define inf                     2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define all(a)                  (a.begin(),a.end())
#define Unique_(a)              sort(all(a));a.erase(unique(all(a)),a.end())
#define mx                      1000005
#define mod                     1000000009
#define left(n)                 (n<<1)
#define right(n)                ((n<<1) + 1)
#define fast                    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PI                      acos(-1)
#define ull                     unsigned long long
#define eps                     .000000001

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}
string tostring(ll res){string curstr="";if(!res) curstr += ((char)res + '0');while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}

/* ...........................................................................................................*/

int vis[1005];
ll dep[1005],totdep[1005];
vector <pair<int,ll> > graph[1005];

struct st
{
    int ind;
    ll cst;
    bool operator <(const st & x)const
    {
        return cst < x.cst;
    }
};

st cost[1005];

void dfs(int cur)
{
    vis[cur] = 1;
    totdep[cur] = dep[cur];
    for(int i=0; i<graph[cur].size(); i++)
    {
        int now = graph[cur][i].first;

        if(!vis[now])
        {
            dfs(now);
            totdep[cur] += totdep[now];
            cost[now].cst = graph[cur][i].second;
            cost[now].ind = now;
            cost[now].cst *= (totdep[now]);//cout<<now<<" "<<totdep[now]<<endl;
        }
    }
}

int main()
{
    int n,k,u,v;
    ll w;

    scanf("%d %d", &n,&k);

    for(int i=1; i<=n; i++) sfll(dep[i]);

    for(int i=1; i<n; i++)
    {
        scanf("%d %d %lld", &u,&v,&w);
        graph[u].pb(mp(v,w));
        graph[v].pb(mp(u,w));
    }

    ll res = 2e18;
    for(int i=1; i<=n; i++)
    {
        mem(vis,0);
        mem(cost,0);
        mem(totdep,0);
        dfs(i);
        cost[i].ind = i;
        cost[i].cst = 2e18;
        cost[0].ind = i;
        cost[0].cst = 2e18;

        //for(int i=1; i<=n; i++) cout<<i<<" "<<cost[i].cst<<" "<<cost[i].ind<<endl;

        sort(cost, cost+n+1);
        ll cur = 0;
        for(int j=0; j<n-k-1; j++)
        {//cout<<i<<" "<<cost[j].ind<<" "<<cost[j].cst<<endl;
            cur += cost[j].cst;
        }
        res = min(cur,res);//out(cur);//system("pause");
    }

    pf("%lld\n", res);

    return 0;
    
}