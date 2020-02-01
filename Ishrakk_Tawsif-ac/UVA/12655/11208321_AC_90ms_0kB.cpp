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
#define mx                      20000+5
#define mod                     1000000007


int n,m,mstpar[mx];

struct ST
{
    int u,v,w;
    bool operator < (const ST & x)const
    {
        return w>x.w;
    }
};

int level[mx];
vector <ST> graph;
vector <pair<int,int> >tree[mx];
pair<int,int> sparse[mx][17],par[mx];

int find_par(int p)
{
    if(mstpar[p] == p) return p;
    return mstpar[p] = find_par(mstpar[p]);
}

void mst()
{
    int cnt = 0;

    sort(graph.begin(),graph.end());

    for(int i=0; i<graph.size(); i++)
    {
        int uu = graph[i].u;
        int vv = graph[i].v;
        int ww = graph[i].w;

            int paru = find_par(uu);
            int parv = find_par(vv);

            if(paru != parv)
            {
                mstpar[paru] = parv;//cout<< uu << " " << vv << " " << ww << endl;
                tree[vv].pb(mp(uu,ww));
                tree[uu].pb(mp(vv,ww));
                cnt++;
                if(cnt == (n-1)) break;
            }
    }
}

void dfs(int cur,int curpar,int lev,int diss)
{
    par[cur].first = curpar;//out(curpar);
    par[cur].second = diss;//out(diss);
    level[cur] = lev;

        for(int i=0; i<tree[cur].size(); i++)
        {
            int vv = tree[cur][i].first;

            if(vv == curpar) continue;

            dfs(vv,cur,lev+1,tree[cur][i].second);
        }
}

void build()
{
    dfs(1,-1,1,0);

        for(int j=1; (1<<j)<=n; j++)
        {
            for(int i=1; i<=n; i++)
            {
                sparse[i][j].first = -1;
                //sparse[i][j].second = inf;
            }
        }

//cout<<sparse[3][2].first<<endl;
        for(int i=1; i<=n; i++) sparse[i][0].first = par[i].first,sparse[i][0].second=par[i].second;

        for(int j=1; (1<<j)<=n; j++)
        {
            for(int i=1; i<=n; i++)
            {
                if(sparse[i][j-1].first != -1)
                {
                    sparse[i][j].first = sparse[sparse[i][j-1].first][j-1].first;
                    sparse[i][j].second = min(sparse[i][j-1].second,sparse[sparse[i][j-1].first][j-1].second);
                }
            }
        }
}

int query(int p,int q)
{
    int log,ans = 1<<30;

    if(level[p]<level[q]) swap(p,q);

    for(log=0; (1<<log)<=level[p]; log++);
    log--;

    for(int i=log; i>=0; i--)
    {
        if(level[p]-(1<<i)>=level[q])
            {
                ans = min(ans,sparse[p][i].second);//cout<<p<<" "<<ans<<endl;
                p = sparse[p][i].first;
            }
    }
//cout<<p<<" ... "<<q<<endl;
    if(p == q) return ans;

    for(int i=log; i>=0; i--)
    {//cout<<p<<" "<<sparse[p][i].first<<" "<<i<<endl;
        if(sparse[p][i].first != -1 && sparse[p][i].first != sparse[q][i].first)
        {
            ans = min(ans,min(sparse[p][i].second,sparse[q][i].second));
            p = sparse[p][i].first;
            q = sparse[q][i].first;//cout<<ans<<endl;
            /*if(ans == 0)*/ //cout<<p << " " << q <<endl;
        }
    }
    return ans = min(ans,min(sparse[p][0].second,sparse[q][0].second));
}

int main()
{//WRITE("in.txt");
    int q,u,v;
    ST get;

    while(~scanf("%d %d %d", &n,&m,&q))
    {

        for(int i=0; i<mx; i++) tree[i].clear();
        graph.clear();

        for(int i=0; i<m; i++)
        {
            scanf("%d %d %d", &get.u,&get.v,&get.w);
            graph.pb(get);
        }

        for(int i=0; i<mx; i++) mstpar[i] = i;
        mst();

        build();

        while(q--)
        {
            scanf("%d %d", &u,&v);
            pf("%d\n", query(u,v));
        }
    }

    return 0;
}