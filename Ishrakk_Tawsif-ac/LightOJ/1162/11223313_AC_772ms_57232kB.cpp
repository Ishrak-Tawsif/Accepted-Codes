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
#define mx                      200000+5
#define mod                     1000000007


int n,m,par[mx],level[mx];

struct ST
{
    int u,v;
    int dg;

    bool operator <(const ST & x) const
    {
        return dg<x.dg;
    }
};

pair<int,pair<int,int> > sparse[mx][17];
vector<pair<int,int> >tree[mx];


void dfs(int cur,int curpar,int lev,int val)
{
    par[cur] = curpar;
    level[cur] = lev;//cout<<cur<<" "<<curpar<<" " << level[cur]<<endl;
    sparse[cur][0].second.first = val;
    sparse[cur][0].second.second = val;

        for(int i=0; i<tree[cur].size(); i++)
        {
            int vv = tree[cur][i].first;
//cout<<cur<<" ....... "<<vv<<endl;
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
                sparse[i][j].second.first = -1;
                sparse[i][j].second.second = -1;
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
                sparse[i][j].second.first = max(sparse[i][j-1].second.first,sparse[sparse[i][j-1].first][j-1].second.first);
                sparse[i][j].second.second = min(sparse[i][j-1].second.second,sparse[sparse[i][j-1].first][j-1].second.second);
            }
        }
    }
}

pair<int,int> query(int p,int q)
{
    int log;
    pair<int,int> ans;
    ans.first = -1;
    ans.second = inf;

    if(level[p]<level[q]) swap(p,q);

    for(log=0; (1<<log)<=level[p]; log++);
    log--;
//cout<<level[p]<<" ........ "<<endl;
    for(int i=log; i>=0; i--)
    {
        if(level[p]-(1<<i)>=level[q])
        {
            ans.first = max(ans.first,sparse[p][i].second.first);
            ans.second = min(ans.second,sparse[p][i].second.second);
            p = sparse[p][i].first;
        }
    }
//cout<<p<<" "<<q<<endl;
    if(p == q) return ans;

    for(int i=log; i>=0; i--)
    {
        if(sparse[p][i].first != -1 && sparse[p][i].first != sparse[q][i].first)
            {
                ans.first = max(ans.first,max(sparse[p][i].second.first,sparse[q][i].second.first));
                ans.second = min(ans.second,min(sparse[p][i].second.second,sparse[q][i].second.second));
                p = sparse[p][i].first,q = sparse[q][i].first;
            }
    }

    ans.first = max(ans.first,max(sparse[p][0].second.first,sparse[q][0].second.first));
    ans.second = min(ans.second,min(sparse[p][0].second.second,sparse[q][0].second.second));

    return ans;
}


int main()
{//WRITE("in.txt");
    ST get;
    int tc,u,v;
    int w;

    scanf("%d", &tc);

    for(int tt=1; tt<=tc; tt++)
    {

        scanf("%d", &n);
        m = n-1;
//out(n);
        for(int i=0; i<mx; i++) tree[i].clear();
        //graph.clear();

        for(int i=0; i<m; i++)
        {
            scanf("%d %d %d", &u,&v,&w);//cout<<u<<" "<<v<<" "<<w<<endl;
            //graph.pb(get);
            tree[u].pb(mp(v,w));
            tree[v].pb(mp(u,w));
        }

        build();

        int q;
        sf(q);

        pf("Case %d:\n", tt);

        while(q--)
        {
            scanf("%d %d", &u,&v);
            pair<int,int> res = query(u,v);

            pf("%d %d\n", res.second,res.first);
        }
    }

    return 0;
}