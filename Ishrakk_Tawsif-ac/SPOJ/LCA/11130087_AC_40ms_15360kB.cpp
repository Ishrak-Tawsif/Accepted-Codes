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
#define mx                      10000007+5
#define mod                     1000000007


int n,level[1005],sparse[1005][18],par[1005];
vector <int> graph[1005];

void dfs(int cur,int curpar,int lev)
{
    level[cur] = lev;
    par[cur] = curpar;
//cout<<curpar<<endl;
        for(int i=0; i<graph[cur].size(); i++)
        {
            int vv = graph[cur][i];
//cout<<cur<<" ... " << vv <<endl;
            if(vv == curpar) continue;

            dfs(vv,cur,lev+1);
        }
}

void build()
{
    dfs(1,-1,1);
    mem(sparse,-1);
    for(int i=1; i<=n; i++) /*par[i] = i,*/sparse[i][0] = par[i];

    for(int j=1; (1<<j)<=n; j++)
    {
          for(int i=1; i<=n; i++) if(sparse[i][j-1] != -1) sparse[i][j] = sparse[sparse[i][j-1]] [j-1];
    }
}

int query(int p,int q)
{

    //dfs(1,-1,1);

    int log;

    if(level[p]<level[q]) swap(p,q);

    for(log = 1; (1<<log)<=level[p]; log++);
    log--;

    for(int i=log; i>=0; i--)
    {
        if(level[p]-(1<<i)>=level[q]) p = sparse[p][i];
    }

    if(p == q) return p;

    for(int i=log; i>=0; i--)
    {
        if(sparse[p][i] != -1 && sparse[p][i] != sparse[q][i]) p = sparse[p][i],q=sparse[q][i];
    }

    return par[p];
}

int main()
{//WRITE("in.txt");
    int tc;

    sf(tc);

    for(int tt=1; tt<=tc; tt++)
    {
        sf(n);

        for(int i=0; i<1005; i++) graph[i].clear();

        int num,u,v;
        for(int i=1; i<=n; i++)
        {
            sf(num);

            while(num--)
            {
                sf(u);
                graph[u].pb(i);//cout<<i<<" " << u <<endl;
                graph[i].pb(u);
            }
        }//cout<<"ok\n";
        build();

        pf("Case %d:\n", tt);

        int q;
        sf(q);
        while(q--)
        {
            scanf("%d %d", &u,&v);
            pf("%d\n", query(u,v));
        }
    }
    return 0;
}