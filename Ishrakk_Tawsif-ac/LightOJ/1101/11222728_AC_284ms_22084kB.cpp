///lca

#include<bits/stdc++.h>
using namespace std;

int dirx[8]={0,0,1,-1,1,1,-1,-1};
int diry[8]={1,-1,0,0,1,-1,1,-1};

#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case #%d\n",nn)
#define out(nn)                 cout <<nn <<endl
#define loop(var,start,till)    for(int var=start; var<till; var++)
#define pb                      push_back
#define mem(a,b)                memset(a,b,sizeof(a))
#define mp                      make_pair
#define ll                      long long int
#define inf                     2e16
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      50000+5
#define mod                     1000000007


int n,m,par[mx],level[mx],mstpar[mx];

struct ST
{
    int u,v;
    ll dg;

    bool operator <(const ST & x) const
    {
        return dg<x.dg;
    }
};

pair<int,ll> sparse[mx][17];
vector <ST> graph;
vector<pair<int,ll> >tree[mx];

int find_par(int p)
{
    if(mstpar[p] == p) return p;
    return mstpar[p] = find_par(mstpar[p]);
}

void mst()
{
    int cnt=0;
    sort(graph.begin(),graph.end());

    for(int i=0; i<graph.size(); i++)
    {
        int uu = graph[i].u;
        int vv = graph[i].v;
        ll cst = graph[i].dg;

            int paru = find_par(uu);
            int parv = find_par(vv);

            if(paru != parv)
            {
                mstpar[paru] = parv;

                tree[uu].pb(mp(vv,cst));//cout<<uu<<" "<<vv<<" "<<cst<<endl;
                tree[vv].pb(mp(uu,cst));
                cnt++;
                if(cnt == (n-1)) break;
            }
    }
}

void dfs(int cur,int curpar,int lev,ll val)
{
    par[cur] = curpar;
    level[cur] = lev;
    sparse[cur][0].second = val;

        for(int i=0; i<tree[cur].size(); i++)
        {
            int vv = tree[cur][i].first;

            if(vv == curpar) continue;

            dfs(vv,cur,lev+1,tree[cur][i].second);
        }
}

int query(int p,int q)
{
    int log;
    ll ans = -1;

    if(level[p]<level[q]) swap(p,q);

    for(log=0; (1<<log)<=level[p]; log++);
    log--;

    for(int i=log; i>=0; i--)
    {
        if(level[p]-(1<<i)>=level[q])
        {
            ans = max(ans,sparse[p][i].second);
            p = sparse[p][i].first;
        }
    }

    if(p == q) return ans;

    for(int i=log; i>=0; i--)
    {
        if(sparse[p][i].first != -1 && sparse[p][i].first != sparse[q][i].first)
            {
                ans = max(ans,max(sparse[p][i].second,sparse[q][i].second));
                p = sparse[p][i].first,q = sparse[q][i].first;
            }
    }

    ans = max(ans,max(sparse[p][0].second,sparse[q][0].second));
    return ans;
}

void build()
{
    dfs(1,-1,1,0);


    for(int j=1; (1<<j)<=n; j++)
    {
            for(int i=1; i<=n; i++)
            {
                sparse[i][j].first = -1;
                sparse[i][j].second = -1;
            }
    }

    for(int i=0; i<=n; i++) sparse[i][0].first = par[i];

    for(int j=1; (1<<j)<=n; j++)
    {
        for(int i=1; i<=n; i++)
        {
            if(sparse[i][j-1].first != -1)
            {
                sparse[i][j].first = sparse[sparse[i][j-1].first][j-1].first;
                sparse[i][j].second = max(sparse[i][j-1].second,sparse[sparse[i][j-1].first][j-1].second);
            }
        }
    }
}

int main()
{//WRITE("in.txt");
    ST get;
    int tc;

    scanf("%d", &tc);

    for(int tt=1; tt<=tc; tt++)
    {

        scanf("%d %d", &n,&m);

        for(int i=0; i<mx; i++) tree[i].clear();
        graph.clear();

        for(int i=0; i<m; i++)
        {
            scanf("%d %d %lld", &get.u, &get.v, &get.dg);
            graph.pb(get);
        }

        for(int i=0; i<=n; i++) mstpar[i] = i;
        mst();
        build();

        int q,u,v;
        sf(q);

        pf("Case %d:\n", tt);

        while(q--)
        {
            scanf("%d %d", &u,&v);
            ll res = query(u,v);

            pf("%lld\n", res);

        }
    }
    return 0;
}