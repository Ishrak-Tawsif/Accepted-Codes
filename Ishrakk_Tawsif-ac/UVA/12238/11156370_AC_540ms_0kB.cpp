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
#define inf                     1e9
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      100005
#define mod                     1000000007

int n,vis[mx],level[mx],par[mx],sparse[mx][18];
ll diss[mx];
vector <pair<int,ll> >graph[mx];

void dfs(int cur,int parent,int lev)
{
    par[cur] = parent;
    level[cur] = lev;

        for(int i=0; i<graph[cur].size(); i++)
        {
            int vv = graph[cur][i].first;
            if(vv == parent) continue;
            dfs(vv,cur,lev+1);
        }
}

void build()
{
    dfs(1,-1,1);

    mem(sparse,-1);
    for(int i=1; i<=n; i++) sparse[i][0] = par[i];

    for(int j=1; (1<<j)<=n; j++)
    {
        for(int i=1; i<=n; i++)
        {
            if(sparse[i][j-1] != -1) sparse[i][j] = sparse[sparse[i][j-1]] [j-1];
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
        if(level[p]-(1<<i)>=level[q]) p = sparse[p][i];
    }

    if(p == q) return p;

    for(int i=log; i>=0; i--)
    {
        if(sparse[p][i] != -1 && sparse[p][i] != sparse[q][i])
            p = sparse[p][i],q = sparse[q][i];
    }

    return par[p];
}

void dfs2(int sr)
{
    vis[sr] = 1;

        for(int i=0; i<graph[sr].size(); i++)
        {
            int vv = graph[sr][i].first;
            if(!vis[vv])
            {
                diss[vv] = diss[sr] + graph[sr][i].second;
                vis[vv] = 1;
                dfs2(vv);
            }
        }
}

void init()
{
    for(int i=0; i<mx; i++) graph[i].clear(),vis[i]=0;
}

int main()
{//WRITE("in.txt");
    int u,v;
    ll cost;

    while(sf(n) == 1 && n)
    {
        init();

        for(int i=1; i<=(n-1); i++)
        {
            scanf("%d %lld", &v,&cost);
            graph[i+1].pb(mp(v+1,cost));
            graph[v+1].pb(mp(i+1,cost));
        }
        build();
        vis[1] = 0;
        diss[1] = 0;
        dfs2(1);

        int q;
//cout<<level[1]<<" "<<level[2]<<endl;
        sf(q);

        for(int qq=1; qq<=q; qq++)
        {
            scanf("%d %d", &u,&v);
            u++,v++;
            int lcauv = query(u,v);//cout<<diss[u]<<" "<<diss[v]<<" "<<diss[lcauv]<<" "<<lcauv<<endl;
            ll res = diss[u]+diss[v]-(2*diss[lcauv]);
            if(qq != 1)pf(" %lld", res);
            else pf("%lld", res);
        }

        pf("\n");
    }

    return 0;
}