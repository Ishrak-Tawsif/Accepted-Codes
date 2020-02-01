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
#define casepf(nn)              printf ("Case %d:\n",nn)
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
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      5000005
#define mod                     1000000007

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

int n,m,vis[2005];
vector <int> graph[2][2005],topsort;

void dfs1(int sr)
{
    vis[sr] = 1;
    for(int i=0; i<graph[0][sr].size(); i++)
    {
        int vv = graph[0][sr][i];
        if(!vis[vv]) dfs1(vv);
    }
    topsort.pb(sr);
}

void dfs2(int sr)
{
    vis[sr] = 1;
    for(int i=0; i<graph[1][sr].size(); i++)
    {
        int vv = graph[1][sr][i];
        if(!vis[vv]) dfs2(vv);
    }
}

void doclear()
{
    for(int i=0; i<2005; i++) graph[0][i].clear(),graph[1][i].clear();
    topsort.clear();
}

int main()
{
    int u,v,tp;
    while(scanf("%d %d", &n,&m))
    {
        if(!n && !m) break;

        doclear();
        for(int i=0; i<m; i++)
        {
            scanf("%d %d %d", &u,&v,&tp);

            if(tp == 1)
            {
                graph[0][u].pb(v);
                graph[1][v].pb(u); /// transpose graph
            }
            else
            {
                graph[0][u].pb(v);
                graph[0][v].pb(u);
                graph[1][u].pb(v);
                graph[1][v].pb(u);
            }
        }
        mem(vis,0);
        for(int i=1; i<=n; i++) if(!vis[i]) dfs1(i);

        mem(vis,0);
        int cnt = 0;
        for(int i=topsort.size()-1; i>=0; i--)
        {
            int vv = topsort[i];

            if(!vis[vv])
            {
                dfs2(vv);
                cnt++;
            }
        }

        cnt == 1? pf("1\n") : pf("0\n");
    }
    return 0;
}