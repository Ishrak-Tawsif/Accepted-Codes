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
#define mx                      100005
#define mod                     7901
#define left(n)                 (n<<1)
#define right(n)                ((n<<1) + 1)
#define fast                    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PI                      acos(-1)
#define ull                     unsigned long long
#define eps                     .000000001
template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}
string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}


/* ...........................................................................................................*/

int n,q,tc,u,v,mstpar[100005],par[mx],vis[mx],level[mx],mark[mx],sparse[mx][17];
ll w,diss[mx];

struct ST
{
    int u,v,w;

    bool operator <(const ST & x) const
    {
        return w<x.w;
    }
};
vector <ST> vv;
vector <pair<int,ll> >graph[100005];

///

void dfs(int cur,int curpar,int lev)
{
    par[cur] = curpar;//cout<<cur<<" p "<<curpar<<endl;
    level[cur] = lev;

        for(int i=0; i<graph[cur].size(); i++)
        {
            int vv = graph[cur][i].first;

            if(vv == curpar) continue;

            dfs(vv,cur,lev+1);
        }
}

void build()
{
    dfs(1,-1,1);

    mem(sparse,-1);
    for(int i=0; i<=n; i++) sparse[i][0] = par[i];

    for(int j=1; (1<<j)<=n; j++)
    {
        for(int i=1; i<=n; i++)
        {
            if(sparse[i][j-1] != -1) sparse[i][j] = sparse[sparse[i][j-1]][j-1];
        }
    }
}

int query(int p,int q)
{
    int log;
    if(level[p]<level[q]) swap(p,q);

    for(log=0; (1<<log)<=level[p]; log++);
    log--;

    for(int i=log; i>=0; i--)
    {
        if(level[p]-(1<<i)>=level[q])p=sparse[p][i];
    }

    if(p == q) return p;

    for(int i=log; i>=0; i--)
    {
        if(sparse[p][i] != -1 && sparse[p][i] != sparse[q][i])
            p = sparse[p][i],q = sparse[q][i];
    }
    return par[p];
}

///

void dfs2(int sr)
{
    vis[sr] = 1;
    for(int i = 0; i<graph[sr].size(); i++)
    {
        int vv = graph[sr][i].first;
        if(!vis[vv])
        {
            diss[vv] = diss[sr] + graph[sr][i].second;
            dfs2(vv);
        }
    }
}

int find_par(int p)
{
    if(mstpar[p] == p) return p;
    else return mstpar[p] = find_par(mstpar[p]);
}

int make_tree()
{
    sort all(vv);
    for(int i=1; i<=n; i++) mstpar[i] = i;
    int tot = 0;
    mem(mark,0);
    for(int i=0; i<vv.size(); i++)
    {
        int u = vv[i].u;
        int v = vv[i].v;
        ll cst = vv[i].w;

        int paru = find_par(u);
        int parv = find_par(v);

            if(paru != parv)
            {
                mark[i] = 1;
                mstpar[paru] = parv;
                graph[u].pb({v,cst});
                graph[v].pb({u,cst});
                tot ++;
                if(tot == n-1) break;
            }
    }
    for(int i=1; i<=n; i++) if(!mark[i]) return i;
}

int main()
{

    sf(tc);
    ST get;

    while(tc --)
    {
        scanf("%d %d", &n,&q);
        vv.clear();
        for(int i=0; i<mx; i++)
        {
            graph[i].clear();
            vis[i] = 0;
            diss[i] = 0;
        }

        for(int i=0; i<n; i++)
        {
            scanf("%d %d %d", &u,&v,&w);
//            graph[u].pb(v);
//            graph[v].pb(u);
              get.u = u;
              get.v = v;
              get.w = w;

              vv.pb(get);
        }
        int notiusededge = make_tree();

//cout<<vv[notiusededge].u<<" "<<vv[notiusededge].v<<endl;

        int dltu = vv[notiusededge].u;
        int dltv = vv[notiusededge].v;

        //graph[dltu].pb({dltv,vv[notiusededge].w});
        //graph[dltv].pb({dltu,vv[notiusededge].w});

        build();
        dfs2(1);

        for(int qr=1; qr<=q; qr++)
        {
            int s,t;
            scanf("%d %d", &s,&t);
            int lcast = query(s,t);//cout<<s<<" ..  "<<t<<" "<<lcast<<endl;
            //cout<<lcast<<endl;
            ll dis1 = (diss[s]+diss[t]-(2*diss[lcast]));
            ll dis2,dis3;

            int lca1 = query(s,dltv);
            int lca2 = query(t,dltu);

            dis2 = (diss[s]+diss[dltv]-(2*diss[lca1]));
            dis2 += (diss[t]+diss[dltu]-(2*diss[lca2]));
            dis2 += vv[notiusededge].w;

            lca1 = query(s,dltu);
            lca2 = query(t,dltv);

            dis3 = (diss[s]+diss[dltu]-(2*diss[lca1]));
            dis3 += (diss[t]+diss[dltv]-(2*diss[lca2]));
            dis3 += vv[notiusededge].w;

            pf("%lld\n", min(dis1,min(dis2,dis3)));
        }
    }

    return 0;
}