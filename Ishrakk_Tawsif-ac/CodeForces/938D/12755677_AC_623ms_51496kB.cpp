#include<bits/stdc++.h>
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
#define pb                      push_back
#define mem(a,b)                memset(a,b,sizeof(a))
#define mp                      make_pair
#define ll                      long long int
#define inf                     2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define all(a)                  (a.begin(),a.end())
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      200005
#define mod                     1000000007

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}

/* ...........................................................................................................*/

struct ST
{
    int v;
    ll cst;
};
vector <ST> graph[mx];

int n,m;
ll vis[mx],diss[mx],tic[mx];

void dikjstra(int sr)
{
    set <pair<ll,int> > q;
    q.insert(mp(tic[sr],sr));
    diss[sr] = min(tic[sr],diss[sr]);
    vis[sr] = 1;

    while(!q.empty())
    {
        pair <ll,int> temp = *q.begin();
        q.erase(q.begin());

        int cur = temp.second;
        ll curcst = temp.first;

        for(int i=0; i<graph[cur].size(); i++)
        {
            int v = graph[cur][i].v;
            ll uvcst = graph[cur][i].cst;
            ll nowcst = curcst+uvcst;
            if(cur == v) nowcst = tic[v];

            if(nowcst<diss[v])
            {
                diss[v] = nowcst;
                q.insert(mp(diss[v],v));
                vis[v] = 1;
            }
        }
    }
}

int main()
{
    int u,v;
    ll c;
    ST get;

    scanf("%d %d", &n,&m);
    for(int i=0; i<m; i++)
    {
        scanf("%d %d %lld", &u,&v,&c);
        get.v = v;
        get.cst = 2*c;
        graph[u].pb(get);
        get.v = u;
        graph[v].pb(get);
    }
    for(int i=1; i<=n; i++)
    {
        scanf("%lld", &tic[i]);
        diss[i] = 2e18;
        get.v = i;
        get.cst = tic[i];
        graph[i].pb(get);
    }

    for(int i=1; i<=n; i++) if(!vis[i])dikjstra(i);
    pf("%lld", diss[1]);

    for(int i=2; i<=n; i++) pf(" %lld", diss[i]);
    pf("\n");

    return 0;
}