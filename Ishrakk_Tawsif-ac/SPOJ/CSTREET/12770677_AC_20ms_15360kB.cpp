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
#define pi                      acos(-1)
#define eps                     1e-7

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}

/* ...........................................................................................................*/

int par[1005];

struct ST
{
    int u,v;
    ll cst;

    bool operator <(const ST & x)const
    {
        return cst<x.cst;
    }
};
vector <ST> graph;
int findpar(int p)
{
    if(par[p] == p) return p;
    return par[p] = findpar(par[p]);
}

ll mst(int n)
{
    ll tot = 0;
    int cnt = 0;

    sort all(graph);

    for(int i=0; i<graph.size(); i++)
    {
        int u = graph[i].u;
        int v = graph[i].v;

        int paru = findpar(u);
        int parv = findpar(v);

        if(paru != parv)
        {
            par[paru] = parv;
            tot += graph[i].cst;//out(tot);
            if(cnt == (n-1)) break;
        }
    }
    return tot;
}

int main()
{
    int n,m,tc;
    ll cost;
    ST get;

    sf(tc);

    while(tc--)
    {
        scanf("%lld", &cost);
        scanf("%d %d", &n,&m);

        for(int i=0; i<m; i++)
        {
            scanf("%d %d %lld", &get.u,&get.v,&get.cst);
            graph.pb(get);
        }

        for(int i=1; i<=n; i++) par[i] = i;
        ll res = mst(n);//out(res);
        res *= cost;

        pf("%lld\n", res);

    }

    return 0;
}