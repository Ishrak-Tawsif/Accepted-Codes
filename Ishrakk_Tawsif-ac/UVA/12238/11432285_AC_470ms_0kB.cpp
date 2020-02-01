#include<bits/stdc++.h>
using namespace std;

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
#define inf                     1e9
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      100000+5
#define mod                     1000000007


int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

int n,sparse[mx][17],par[mx],level[mx],vis[mx];
ll diss[mx];
vector <pair<int,ll> > tree[mx];

void dfs(int cur,int curpar,int lev)
{
    par[cur] = curpar;
    level[cur] = lev;

        for(int i=0; i<tree[cur].size(); i++)
        {
            int vv = tree[cur][i].first;

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

void dfs2(int sr)
{
    vis[sr] = 1;
    for(int i = 0; i<tree[sr].size(); i++)
    {
        int vv = tree[sr][i].first;
        if(!vis[vv])
        {
            diss[vv] = diss[sr] + tree[sr][i].second;
            dfs2(vv);
        }
    }
}

int main()
{//WRITE("in.txt");
    int u;
    ll v;

    while(scanf("%d", &n) && n)
    {

        for(int i=0; i<mx; i++)
        {
            tree[i].clear();
            vis[i] = 0;
            diss[i] = 0;
        }

        for(int i=1; i<=(n-1); i++)
        {
            scanf("%d %lld", &u,&v);
            tree[i].pb(mp(u,v));
            tree[u].pb(mp(i,v));
        }
        build();
        dfs2(1);


        int que;
        sf(que);
        for(int qr=1; qr<=que; qr++)
        {
            int s,t;
            scanf("%d %d", &s,&t);
            int lcast = query(s,t);
            //cout<<lcast<<endl;
            qr==1? pf("%lld", (diss[s]+diss[t]-(2*diss[lcast]))) : pf(" %lld", (diss[s]+diss[t]-(2*diss[lcast])));
        }
        pf("\n");
    }
    return 0;
}